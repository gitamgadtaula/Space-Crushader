// This code will work only if you selected window, graphics and audio.
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

#include "player.hpp"
#include "entity.hpp"
#include "projectile.hpp"
using namespace std;
// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
int main(int, char const**)
{
    int counter=0;
    int counter2=0;
    int counter3=0;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Space Crushader by KU scholars");
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Space Crushader", font, 30);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x/2-(110),0);
    text.setOutlineColor(sf::Color::Yellow);
    
    // Load a sprite to display
    //main sprite
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile(resourcePath() + "ship.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spritePlayer(texturePlayer);
    texturePlayer.setSmooth(true);
    
    sf::Texture textureEnemy;
    if (!textureEnemy.loadFromFile(resourcePath() + "CA.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteEnemy(textureEnemy);
    spriteEnemy.setScale(sf::Vector2f(0.5f, 0.5f));
    texturePlayer.setSmooth(true);
    spriteEnemy.setPosition(900,30);
    
    //background
    sf::Texture textureBackground;
    //sf::IntRect Rect;
    if (!textureBackground.loadFromFile(resourcePath() + "Background-space.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteBackground(textureBackground);
    textureBackground.setSmooth(true);
    
    // Play the music
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile((resourcePath() +"mainmenu.wav")))
        return -1;
    sf::Sound sound;
    sound.setBuffer(buffer);
    //sound.play();
    sf::Music music;
    if (!music.openFromFile(resourcePath()+ "laser.wav"))
        return -1; // error
    
    
    class player Player1;
    Player1.sprite.setTexture(texturePlayer);
    //Player1.sprite.setScale(sf::Vector2f(0.8f, 0.9f));
    
    // Projectile Vector Array
    vector<projectile>::const_iterator iter;
    vector<projectile> projectileArray;
    
    //projectile object
    class projectile projectile1;
    
    //The game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                window.close();
            }
        }
        
        // Clear screen
        window.clear();
        window.draw(spriteBackground);
        window.draw(text);
        
        // Fires Missle (Space bar)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2+45,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2+20);
            projectile1.direction = Player1.direction;
            projectileArray.push_back(projectile1);
            //laser sound

            music.play();
            }
      
        // Draw Projectiles
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            projectileArray[counter].update(); // Update Projectile
            window.draw(projectileArray[counter].rect);
            counter++;
        }
        
        // Update Player
        Player1.update();
        Player1.updateMovement();
        
        window.draw(Player1.sprite);
        window.draw(spriteEnemy);
        spriteEnemy.move(-0.6,0);
        
        //spriteEnemy.move(-0.1,0);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
