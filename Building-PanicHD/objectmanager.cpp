#include "objectmanager.h"

void ObjectManager::add(const int &m, const int &n, std::unique_ptr<Object> block_)
{
    board_.insert(make_pair(m, std::map<int, std::unique_ptr<Object>>()));
    board_[m].insert(make_pair(n, std::move(block_)));
}

void ObjectManager::Reverse(const int &m, const int &n, const Object::Color &color)
{
    int Intcolor = static_cast<int>(color);
    board_[m][n]->SetFill();
    board_[m][n]->Paint(color);
    bool reverse = false;
    if( board_[m][n]->getFill() == Object::Fill::full_full){
        for (int i = n; i < columns; i++)
        { // to left
            if (board_[m][i]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[m][i]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            else if ( i+1 != columns && board_[m][i + 1]->getIntColor() == Intcolor && reverse == false)
            {
                reverse = false;
                break;
            }
            if (board_[m][i]->getFill() == Object::Fill::full_full
                    && board_[m][i]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = n; k < i; k++)
                {
                    board_[m][k]->Paint(color);
                }
                break; //or continue?
            }

        }
        for (int i = n; i >= 0; i--)
        { // to right
            if (board_[m][i]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[m][i]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            else if (i-1 > 0 && board_[m][i - 1]->getIntColor() == Intcolor && reverse == false)
            {
                reverse = false;
                break;
            }
            if (board_[m][i]->getFill() == Object::Fill::full_full
                    && board_[m][i]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = n; k > i; k--)
                {
                    board_[m][k]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m; i >= 0; i--)
        { // up
            if (board_[i][n]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][n]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if ( board_[i][n]->getFill() == Object::Fill::full_full &&
                    board_[i][n]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m; k > i; k--)
                {
                    board_[k][n]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m; i < rows; i++)
        { // down
            if (board_[i][n]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][n]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if ( board_[i][n]->getFill() == Object::Fill::full_full &&
                    board_[i][n]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m; k < i; k++)
                {
                    board_[k][n]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m, j = n; i < rows && j < columns; j++ && i++)
        { // \ from r to l
            if (board_[i][j]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][j]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if ( board_[i][j]->getFill() == Object::Fill::full_full &&
                    board_[i][j]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m, l = n; k < i && l < j; l++ && k++)
                {
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m, j = n; i >= 0 && j >= 0; j-- && i--)
        { // \ from l to r
            if (board_[i][j]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][j]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if (board_[i][j]->getFill() == Object::Fill::full_full &&
                    board_[i][j]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m, l = n; k > i && l > j; l-- && k--)
                {
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m, j = n; i < rows && j >= 0; j-- && i++)
        { // / left to right
            if (board_[i][j]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][j]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if ( board_[i][j]->getFill() == Object::Fill::full_full &&
                    board_[i][j]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m, l = n; k < i && l > j; l-- && k++)
                {
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
        reverse = false;
        for (int i = m, j = n; i >= 0 && j < columns; j++ && i--)
        { // / left to right
            if (board_[i][j]->getIntColor() == -Intcolor && reverse == false)
            {
                reverse = true;
            }
            else if (board_[i][j]->getIntColor() == 0)
            {
                reverse = false;
                break;
            }
            if ( board_[i][j]->getFill() == Object::Fill::full_full &&
                    board_[i][j]->getIntColor() == Intcolor && reverse == true)
            {
                for (int k = m, l = n; k > i && l < j; l++ && k--)
                {
                    board_[k][l]->Paint(color);
                }
                break;
            }
        }
    }
}

const std::map<int, std::map<int, std::unique_ptr<Object>>> &ObjectManager::getBoard()
{
    return board_;
}

void ObjectManager::addScore(Player &gracz, Enemy &enemy){
    while(!end_game)
    {
        for (const auto &el : board_)
        {

            for (const auto &v : el.second)
            {
                if (v.second->getColor_Object() == gracz.getColor_Object())
                {
                    gracz.addScore(175);
                }
                if (v.second->getColor_Object() == enemy.getColor_Object() )
                {
                    enemy.addScore(175);
                }
            }
        }
        end_game = true;
    }
}

void ObjectManager::Paint(const sf::RenderWindow &window, const sf::Event &event)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    std::cerr << "XY M : " << mouse_pos.x << " y : " << mouse_pos.y << std::endl;
    for (auto &bd : board_)
    {
        for (auto &bd_el : bd.second)
        {
            if (bd_el.second->getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    bd_el.second->Paint(Object::Color::Player);
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    bd_el.second->Paint(Object::Color::Enemy);
                }
            }
        }
    }
}

void ObjectManager::Paint(Hero &hero)
{
    sf::FloatRect playerBounds = hero.getGlobalBounds();
    for (auto &bd : board_)
    {
        int m = bd.first;
        for (auto &bd_el : bd.second)
        {

            if (bd_el.second->getGlobalBounds().contains(playerBounds.left + playerBounds.width / 2.0, playerBounds.top + playerBounds.height - 10))
                //&& bd_el.second->getGlobalBounds().contains(playerBounds.left, playerBounds.top + playerBounds.height - 10))
            {
                if( hero.painting() && hero.can_paint() )
                {
                    if(bd_el.second->getFill() !=  Object::Fill::full_full)
                    {
                        int n = bd_el.first;
                        this->Reverse(m, n, hero.getColor_Object());
                        hero.addScore(25);
                    }
                }
            }
        }
    }
}


bool ObjectManager::full_board()
{
    for (const auto &el : board_)
    {
        for (const auto &v : el.second)
        {
            if ( v.second->getFill() < Object::Fill::full_full )
            {
                return false;
            }
        }
    }
    return true;
}

void ObjectManager::draw()
{
    for (const auto &el : board_)
    {
        for (const auto &v : el.second)
        {
            if( v.second->is_visible()){

                window_->draw(*v.second);
            }
        }
    }
}

ObjectManager::ObjectManager(sf::RenderWindow *window) : window_(window)
{
    if (!texture.loadFromFile("Texture/Dungeons Walls.png"))
    {
        throw("Could not load texture 'Dungeons Walls'");
    }
    texture.setRepeated(true);
    for (int i = 0; i < columns; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            std::unique_ptr<Object> block_ = std::make_unique<Object>(sf::Vector2f(x, y), texture);
            this->add(k, i, std::move(block_));
            y += 247;
        }
        x+= 7.25 * 32;
        y = 25.0 ;
    }
}
