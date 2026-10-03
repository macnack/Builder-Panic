#include "assets.h"

#include <filesystem>
#include <map>
#include <stdexcept>
#include <unistd.h>

namespace fs = std::filesystem;

namespace {

fs::path executableDir()
{
    char buf[4096];
    const ssize_t n = ::readlink("/proc/self/exe", buf, sizeof(buf) - 1);
    if (n < 0)
        return fs::current_path();
    buf[n] = '\0';
    return fs::path(buf).parent_path();
}

} // namespace

std::string assetPath(const char *relative)
{
    const fs::path rel(relative);
    const fs::path exe = executableDir();
    const fs::path cwd = fs::current_path();
    const fs::path candidates[] = {
        exe / "Resources" / rel,
        exe / ".." / "Resources" / rel,
        exe / ".." / ".." / "Resources" / rel,
        cwd / "Resources" / rel,
        cwd / ".." / "Resources" / rel,
        cwd / rel,
    };
    for (const fs::path &candidate : candidates)
    {
        std::error_code ec;
        if (fs::is_regular_file(candidate, ec))
            return candidate.lexically_normal().string();
    }
    return (cwd / "Resources" / rel).lexically_normal().string();
}

const sf::Texture &cachedTexture(const char *relative, bool repeated)
{
    static std::map<std::string, sf::Texture> cache;
    auto found = cache.find(relative);
    if (found == cache.end())
    {
        sf::Texture texture;
        const std::string path = assetPath(relative);
        if (!texture.loadFromFile(path))
            throw std::runtime_error("Could not load texture " + path);
        if (repeated)
            texture.setRepeated(true);
        found = cache.emplace(relative, std::move(texture)).first;
    }
    else if (repeated && !found->second.isRepeated())
    {
        found->second.setRepeated(true);
    }
    return found->second;
}
