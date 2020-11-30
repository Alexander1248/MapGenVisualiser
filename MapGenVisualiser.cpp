#include "SFML/Graphics.hpp"
#include "WorldGenerator.h"
#include <iostream>
#include <Windows.h>


using namespace std;
using namespace sf;

int main() {
	Vec2 mapSize;

	mapSize.x = 1024;
	mapSize.y = 1024;
	int hmax = 10000;
	float maxT = 50; float minT = -10;
	float waterCoef = 8.5;
	int waterLevel = 2000; int mountianLevel = 5000;
	int kRivers = 50; int riverLen = 100000; float rivRandRer = 25;
	int scale = 50;
	string seed = "test";
	string type = "CoredPlane";


	int tdat = 0;
	int state = 0;
	Font font;
	font.loadFromFile("123.ttf");
	Texture map;
	Sprite img;
	RectangleShape button(Vector2f({ 200,50 }));
	RenderWindow window(sf::VideoMode(1280, 720), "WorldGen");
	while (window.isOpen()) {
		window.clear();
		Event event;
		while (window.pollEvent(event))
		{
			// "запрос закрытия" событие: мы закрываем окно
			if (event.type == sf::Event::Closed)
				window.close();
		}
		map.loadFromFile("map.png");
		img.setTexture(map);
		img.setPosition(Vector2f({ 560,0 }));
		img.setScale(Vector2f({ 720.f / mapSize.x ,720.f / mapSize.y }));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			state--;
			if (state < 0) state = 12;
			Sleep(1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			state++;
			if (state > 13) state = 0;
			Sleep(1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (state == 0) mapSize.x++;
			if (state == 1) mapSize.y++;
			if (state == 2) hmax++;
			if (state == 3) maxT += 0.1;
			if (state == 4) minT += 0.1;
			if (state == 5) waterCoef += 0.1;
			if (state == 6) waterLevel++;
			if (state == 7) mountianLevel++;
			if (state == 8) kRivers++;
			if (state == 9) riverLen++;
			if (state == 10) rivRandRer += 0.1;
			if (state == 11) scale++;
			if (state == 12) tdat++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (state == 0) mapSize.x--;
			if (state == 1) mapSize.y--;
			if (state == 2) hmax--;
			if (state == 3) maxT -= 0.1;
			if (state == 4) minT -= 0.1;
			if (state == 5) waterCoef -= 0.1;
			if (state == 6) waterLevel--;
			if (state == 7) mountianLevel--;
			if (state == 8) kRivers--;
			if (state == 9) riverLen--;
			if (state == 10) rivRandRer -= 0.1;
			if (state == 11) scale--;
			if (state == 12) tdat--;
		}
		if (abs(tdat) % 3 == 0)  type = "Sphere";
		if (abs(tdat) % 3 == 1)  type = "CoredPlane";
		if (abs(tdat) % 3 == 2)  type = "Plane";

		CircleShape use(5);
		use.setPosition(Vector2f({ 15,17.5f + 40.f * state }));
		Vector2i localPosition = Mouse::getPosition(window);
		Text text("TEST!!!", font, 20);
		button.setPosition(Vector2f({ 10,660 }));
		text.setPosition(Vector2f({ 90,675 }));
		text.setFillColor(Color::Black);
		window.draw(button);
		window.draw(text);
		window.draw(use);
		window.draw(img);

		text.setString("Width: " + to_string(mapSize.x));
		text.setPosition(Vector2f({ 30,10 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Height: " + to_string(mapSize.y));
		text.setPosition(Vector2f({ 30,50 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Max lift: " + to_string(hmax));
		text.setPosition(Vector2f({ 30,90 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Max temperature: " + to_string(maxT));
		text.setPosition(Vector2f({ 30,130 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Min temperature: " + to_string(minT));
		text.setPosition(Vector2f({ 30,170 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Water coeficent: " + to_string(waterCoef));
		text.setPosition(Vector2f({ 30,210 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Water level: " + to_string(waterLevel));
		text.setPosition(Vector2f({ 30,250 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Mountian level: " + to_string(mountianLevel));
		text.setPosition(Vector2f({ 30,290 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Number of rivers: " + to_string(kRivers));
		text.setPosition(Vector2f({ 30,330 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("River lenght: " + to_string(riverLen));
		text.setPosition(Vector2f({ 30,370 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Percentage of randomization of rivers: " + to_string(rivRandRer));
		text.setPosition(Vector2f({ 30,410 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Scale: " + to_string(scale));
		text.setPosition(Vector2f({ 30,450 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("Generation type: " + type);
		text.setPosition(Vector2f({ 30,490 }));
		text.setFillColor(Color::White);
		window.draw(text);
		text.setString("World seed: " + seed);
		text.setPosition(Vector2f({ 30,530 }));
		text.setFillColor(Color::White);
		window.draw(text);

		window.display();
		if (state == 13) cin >> seed, state = 0;

		if (localPosition.x >= 10 && localPosition.x <= 210 && localPosition.y >= 660 && localPosition.y <= 710) {
			button.setFillColor(Color::Green);
			if (Mouse::isButtonPressed(sf::Mouse::Left)) {
				Image map;
				Uint8* pix = new Uint8[mapSize.x * mapSize.y * 4];
				float** data = new float* [4];
				for (int i = 0; i < 4; i++) data[i] = new float[mapSize.x * mapSize.y];
				cout << "Creating started..." << endl;
				WorldGen(data, mapSize, hmax, seed, type, maxT, minT, waterCoef, waterLevel, mountianLevel, kRivers, riverLen, rivRandRer, scale);
				cout << "Creating completed!" << endl;
				cout << "Saving file..." << endl;
				for (int i = 0; i < mapSize.x * mapSize.y; i++) {
					if (float(data[0][i]) < 2000) pix[i * 4] = 0, pix[i * 4 + 1] = 0, pix[i * 4 + 2] = data[0][i] * 255 / 2000, pix[i * 4 + 3] = 255;
					else pix[i * 4] = data[0][i] * 255 / 10000, pix[i * 4 + 1] = data[0][i] * 255 / 10000, pix[i * 4 + 2] = data[0][i] * 255 / 10000, pix[i * 4 + 3] = 255;
				}
				map.create(mapSize.x, mapSize.y, pix);
				map.saveToFile("hmap.png");

				for (int i = 0; i < mapSize.x * mapSize.y; i++) pix[i * 4] = 0, pix[i * 4 + 1] = 0, pix[i * 4 + 2] = data[1][i] * 255 / 1000, pix[i * 4 + 3] = 255;
				map.create(mapSize.x, mapSize.y, pix);
				map.saveToFile("pmap.png");

				for (int i = 0; i < mapSize.x * mapSize.y; i++) {
					pix[i * 4] = 4.25 * (data[2][i] + 10);
					pix[i * 4 + 1] = 0;
					pix[i * 4 + 2] = 4.25 * (50 - data[2][i]);
					pix[i * 4 + 3] = 255;
				}
				map.create(mapSize.x, mapSize.y, pix);
				map.saveToFile("tmap.png");

				for (int i = 0; i < mapSize.x * mapSize.y; i++) {
					if (data[3][i] == 1) {
						pix[i * 4] = 0, pix[i * 4 + 1] = 0, pix[i * 4 + 2] = 255, pix[i * 4 + 3] = 255;
					}
					else {
						pix[i * 4] = 255, pix[i * 4 + 1] = 255, pix[i * 4 + 2] = 255, pix[i * 4 + 3] = 255;
					}
				}
				map.create(mapSize.x, mapSize.y, pix);
				map.saveToFile("rmap.png");

				for (int i = 0; i < mapSize.x * mapSize.y; i++) {
					if (data[3][i] == 1) {
						pix[i * 4] = 0, pix[i * 4 + 1] = 0, pix[i * 4 + 2] = 255, pix[i * 4 + 3] = 255;
					}
					else {
						if (float(data[0][i]) < 2000) pix[i * 4] = 0, pix[i * 4 + 1] = 0, pix[i * 4 + 2] = data[0][i] * 255 / 2000, pix[i * 4 + 3] = 255;
						else pix[i * 4] = data[0][i] * 255 / 10000, pix[i * 4 + 1] = data[0][i] * 255 / 10000, pix[i * 4 + 2] = data[0][i] * 255 / 10000, pix[i * 4 + 3] = 255;
					}
				}
				map.create(mapSize.x, mapSize.y, pix);
				map.saveToFile("hrmap.png");

				for (int i = 0; i < mapSize.x * mapSize.y; i++) {
					if (data[3][i] == 1 && data[0][i] >= 2000) {
						if (data[2][i] <= 0) {
							pix[i * 4] = pow(1.6987, -data[2][i]);
							pix[i * 4 + 1] = pow(1.7405, -data[2][i]);
							pix[i * 4 + 2] = 250;
						}
						else {
							pix[i * 4] = 0;
							pix[i * 4 + 1] = 0;
							pix[i * 4 + 2] = 255;
						}
					}
					else {
						if (float(data[0][i]) <= 2000) {
							if (data[2][i] <= 0) {
								pix[i * 4] = pow(1.6987, -data[2][i]);
								pix[i * 4 + 1] = pow(1.7405, -data[2][i]);
								pix[i * 4 + 2] = 250;
							}
							else {
								pix[i * 4] = 0;
								pix[i * 4 + 1] = 0;
								pix[i * 4 + 2] = data[0][i] * 255 / 2000;
							}
						}
						else {
							if (data[2][i] <= 0) {
								pix[i * 4] = (data[0][i] * 255 / 10000 + 255) / 2;
								pix[i * 4 + 1] = (data[0][i] * 255 / 10000 + 255) / 2;
								pix[i * 4 + 2] = (data[0][i] * 255 / 10000 + 255) / 2;
							}
							else {
								pix[i * 4] = data[2][i] * 255 / 50;
								pix[i * 4 + 1] = sqrt(data[1][i] * 64.99);
								pix[i * 4 + 2] = 0;
							}
						}
					}
					pix[i * 4 + 3] = 255;
				}
				map.create(mapSize.x, mapSize.y, pix);
				map.saveToFile("map.png");

				cout << "File saved!" << endl;
			}

		}
		else button.setFillColor(Color::White);
	}
}