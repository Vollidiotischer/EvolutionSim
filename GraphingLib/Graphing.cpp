#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Graphing.hpp"


namespace Graphing {


	Graph::Graph(std::string title, std::string x_axis_title, std::string y_axis_title) {
		this->title = title; 
		this->x_axis = x_axis_title; 
		this->y_axis = y_axis_title; 
	}

	void Graph::draw(sf::RenderWindow& window) {
		this->resize_axis();

		// draw background
		sf::RectangleShape background({ (float)this->w, (float) (-this->h) }); 
		background.setPosition({ (float)this->x, (float)this->y }); 
		background.setFillColor(sf::Color(0, 0, 0, 100)); 
		window.draw(background); 

		// draw y-axis
		sf::RectangleShape rect({ (float) this->line_thickness, (float) (-this->h)});
		rect.setFillColor(sf::Color::Magenta); 
		rect.setPosition({ (float)this->x, (float)this->y }); 
		window.draw(rect); 

		// draw x-axis
		rect.setSize({ (float)(this->w), (float) this->line_thickness });
		window.draw(rect);

		// draw data points
		sf::CircleShape point(this->line_thickness, 5);
		point.setFillColor(sf::Color::Black); 
		point.setOrigin({(float) (this->line_thickness / 2.0), (float) (this->line_thickness / 2.0)}); // move Circle origin to center of circle
		for (int i = 0; i < data.size(); i++) {

			this->draw_data_point(window, point, data[i]);


		}


		// draw title texts

		// draw scalar texts


	}

	void Graph::draw_data_point(sf::RenderWindow& rw, sf::CircleShape& drawable_point, std::pair<double, double>& dp) {
		// if data pair is in visible x range then calculate the y component
		double delta_x = x_range.second - x_range.first;
		double delta_x_data = dp.first - x_range.first;
		double x_factor = delta_x_data / delta_x;

		// check if x point is in range
		if (!(x_factor >= 0.0 && x_factor <= 1.0)) {
			return; 
		}

		double delta_y = y_range.second - y_range.first; // get size of y range
		double delta_y_data = dp.second - y_range.first; // get data y value normalized with bottom value of y range
		double y_factor = delta_y_data / delta_y;

		// check if y point is in range
		if (!(y_factor >= 0.0 && y_factor <= 1.0)) {
			return; 
		}

		// draw point
		drawable_point.setPosition({ (float)(this->x + this->w * x_factor), (float)(this->y - this->h * y_factor) });
		rw.draw(drawable_point);


	}

	// updates the graph (adds newest values to the Graph) 
	void Graph::add_element(double x, double y) {
		data.push_back(std::pair<double, double>(x, y));


	}

	void Graph::resize_axis() {
		// set x_range and y_range so that a good graph is shown
	}



	void Graph::set_x_range(double start, double end) {
		this->x_range.first = start; 
		this->x_range.second = end; 
	}

	void Graph::set_y_range(double start, double end) {
		this->y_range.first = start; 
		this->y_range.second = end; 
	}

	void Graph::set_pos(int x, int y) {
		this->x = x; 
		this->y = y; 
	}

	void Graph::set_dim(int width, int height) {
		this->w = width; 
		this->h = height; 
	}

	void Graph::set_line_thickness(int thickness) {
		this->line_thickness = thickness; 
	}

}