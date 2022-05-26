#include <iostream>
#include <SFML/Graphics.hpp>
#include "GraphingLib/Graphing.hpp"

namespace MainLoop {

	void run() {

		sf::RenderWindow window(sf::VideoMode(500, 500), "Evo");

		Graphing::Graph graph("title", "x-axis", "y-axis"); 
		graph.set_dim(300, 100); 
		graph.set_pos(100, 400); 
		graph.set_x_range(0, 10); 
		graph.set_y_range(5, 10); 

		graph.add_element(0, 1); 
		graph.add_element(1, 2); 
		graph.add_element(2, 3); 
		graph.add_element(3, 3); 
		graph.add_element(3, 4); 
		graph.add_element(4, 5); 
		graph.add_element(5, 6); 
		graph.add_element(6, 7); 
		graph.add_element(7, 8); 
		graph.add_element(8, 9); 
		graph.add_element(9, 10); 
		graph.add_element(10, 11); 


		while (window.isOpen()) {
			sf::Event events;
			while (window.pollEvent(events)) {
				if (events.type == sf::Event::Closed) {
					window.close();
				}
			}


			window.clear(sf::Color::White);
			graph.draw(window); 
			window.display(); 
		}

	}

}