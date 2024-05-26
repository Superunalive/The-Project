#include <SFML/Graphics.hpp>

int main() {
    // Размеры окна
    const int windowWidth = 800;
    const int windowHeight = 800;
    const int cellSize = 40; //  одна клетка

    // Создание окна
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Game Dev Grid");

    // Главный цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Очистка окна
        window.clear();

        // Рисование сетки
        for (int x = 0; x <= windowWidth; x += cellSize) {
            for (int y = 0; y <= windowHeight; y += cellSize) {
                sf::RectangleShape cell;
                cell.setSize(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(x, y);
                cell.setFillColor(sf::Color(200, 200, 200)); // Цвет клеток
                window.draw(cell);
            }
        }

        // Отображение изменений
        window.display();
    }

    return 0;
}
