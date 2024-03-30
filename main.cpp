#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;
int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }





    // cout << "Program's working" << endl;
    // auto window = sf::RenderWindow{ { 1920u, 1080u }, "Practika PKSH" };
    // window.setFramerateLimit(144);
    // while (window.isOpen()) {
    //     for (auto event = sf::Event{}; window.pollEvent(event);) {
    //         if (event.type == sf::Event::Closed) {
    //             window.close();
    //         }
    //     }
    //     window.clear();
    //     window.display();
    // }


    // HWND hwndButton = CreateWindow( 
    // L"BUTTON",  // Predefined class; Unicode assumed 
    // L"OK",      // Button text 
    // WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
    // 10,         // x position 
    // 10,         // y position 
    // 100,        // Button width
    // 100,        // Button height
    // m_hwnd,     // Parent window
    // NULL,       // No menu.
    // (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE), 
    // NULL);      // Pointer not needed.

    return 0;
}