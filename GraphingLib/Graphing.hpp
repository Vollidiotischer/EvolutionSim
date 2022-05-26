#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

namespace Graphing {

	class Graph {

	private:
		/*
			Drawing Stuff: 
		*/
		int x, y;
		int w, h;
		int line_thickness = 3; 

		/*
			Data Stuff: 
		*/
		// whether the Grapoh should automatically rescale
		bool automatic_rescalable = true;
		bool titles_activated = true; 
		bool scales_activated = true; 
		
		// The title of the Graph and its axis
		std::string title; 
		std::string x_axis;
		std::string y_axis;

		// the (visible) coordinates which are shown on the axis (first is leftmost value and second is rightmost value) -> so the range which the axis currently shows
		std::pair<double, double> x_range;  
		std::pair<double, double> y_range;

		// all the x, y data pairs in the Graph
		std::vector<std::pair<double, double>> data; 


	public: 
		// used for data
		Graph(std::string, std::string, std::string); 
		void add_element(double, double);

		void resize_axis();  

		void set_x_range(double, double); 
		void set_y_range(double, double); 

		// used for drawing
		void draw(sf::RenderWindow&);
		void set_pos(int, int);
		void set_dim(int, int);
		void set_line_thickness(int);
	private: 
		void draw_data_point(sf::RenderWindow&, sf::CircleShape&, std::pair<double, double>&);
	};

}