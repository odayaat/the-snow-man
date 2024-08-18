#include "Controller.h"
#include <windows.h>
void Controller::runGame(sf::RenderWindow& window)
//===============runGame==================
//The functions runs the game
{
    sf::Clock time;

    m_board.readBoard();
 
    while (window.isOpen())
    {
        float timeThatWasPassed = time.restart().asSeconds();
        sf::Vector2i dir = getDir();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            m_board.shotBullet(SHOT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            m_board.shotRcoket(ROCKET);
        m_board.move(dir, timeThatWasPassed);
        m_board.handleCollision();
        if (m_board.isGameOver())
            break;
        m_board.moveAutoObjects(timeThatWasPassed);
        setView(window);
        window.clear();
        m_board.drawBoard(window);//draw game
        window.display();
    }
    displayTheScore(window);

}
void Controller::displayTheScore(sf::RenderWindow& window) 
//===========displayTheScore=========
//The function display the score for four seconds
{

    auto view = sf::View(sf::FloatRect(0, 0, 1550, 800));
    window.setView(view);
    m_scoreText.setString("Your score:" + std::to_string(m_board.getScore()));
    window.clear();
    window.draw(m_gameOverBackground);
    window.draw(m_scoreText);
    window.display();
    Sleep(FOR_SECONDS);

}
sf::Vector2i Controller::getDir() 
//===============runGame==================
//returns the direction that user has pressed
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return sf::Vector2i(-1, 0);//left

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return sf::Vector2i(0, 1);//down

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return sf::Vector2i(1, 0);//right

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return sf::Vector2i(0, -1);//up

    return sf::Vector2i(0, 0);//stand
}
Controller::Controller()
//==============Constructor===================
{
    m_gameOverBackground.setTexture(*SingeltonTexture::instance().getTexture(BACKGROUND, GAME_OVER_BACKGROUND));
    m_scoreText.setCharacterSize(60);
    m_scoreText.setFillColor(sf::Color::Black);
    m_scoreText.setFont(*SingeltonFont::instance().getFontGame(SUPER_MARIO_FONT));
    m_scoreText.setPosition(WIDTH / 2 -230, HEIGHT / 2);
}


void Controller::setView(sf::RenderWindow& window) 
//================setView================
//The function moves the screen and information bar to right, left or stay . 
{

   
    auto newView = window.getView();
     const sf::Vector2f playerLocation = *m_board.getLocationOfPlayer();

     //if the player is on the left side of the screen relative to the center
    if (playerLocation.x - window.getSize().x / 2 < 0) 
    {
        newView.setCenter(window.getSize().x / 2 , newView.getCenter().y);
        m_board.setBoardPostion(window.getSize().x / 2);
    }
    else if ((playerLocation.x + window.getSize().x / 2) > THE_LENGTH_OF_SCREEN)//checks if in end of map
    {
        newView.setCenter(THE_LENGTH_OF_SCREEN - newView.getSize().x / 2 , newView.getCenter().y);
        m_board.setBoardPostion(THE_LENGTH_OF_SCREEN - newView.getSize().x / 2);
    }
    else {
        newView.setCenter(playerLocation.x , newView.getCenter().y);
        m_board.setBoardPostion(playerLocation.x);
    }

    window.setView(newView);
}