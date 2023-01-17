#include "aide.h"
#include "functions.h"
using namespace sf;
int main()
{
	srand(time(nullptr));
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	RectangleShape Bat;
	initBat(Bat, BatColor, BatStartPos);
	float BatSpeedX = 0.f;
	CircleShape ball;
	initBall(ball, BALL_COLOR, ballStartPos);
	RectangleShape arr_rect[size];
for (int i = 0; i < size; i++) {
		arr_rect[i].setSize(Vector2f(batWidth, batHeight2));
		arr_rect[i].setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
		arr_rect[i].setOutlineThickness(5);
		arr_rect[i].setOutlineColor(Color::Black);
		float x = 0.f;
		float y = 0.f;
		arr_rect[i].setPosition(x * i, y);
		x = 80.f;
		y = 0.f;
		arr_rect[i].setPosition(x * i, y);	
	}
RectangleShape arr_rect2[size];
for (int i = 0; i < size; i++) {
	arr_rect2[i].setSize(Vector2f(batWidth,batHeight2));
	arr_rect2[i].setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
	arr_rect2[i].setOutlineThickness(5);
	arr_rect2[i].setOutlineColor(Color::Black);
	float x = 0.f;
	float y = 50.f;
	arr_rect2[i].setPosition(x * i, y);
	x = 80.f;
	y = 50.f;
	arr_rect2[i].setPosition(x * i, y);
}
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];
	int PlayerScore = 0;

	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text PlayerScoreText;
	initText(PlayerScoreText, PlayerScore, font, charSize, TextStartPos);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		ball.move(ball_speedx, ball_speedy);
		if (ball.getPosition().y <= 0)
		{
			ball_speedy = -ball_speedy;
		}
		if (ball.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS))
		{
			window.close();
		}
		if (ball.getPosition().x <= 0 || ball.getPosition().x >=
			(WINDOW_WIDTH - 2 * BALL_RADIUS))
		{
			ball_speedx = -ball_speedx;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) { Bat.move(-5, 0); }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { Bat.move(5, 0); }
		if (Bat.getPosition().x <= 0) {
			Bat.setPosition(0.f, WINDOW_HEIGHT - 2 * batHeight);
		}
		if (Bat.getPosition().x + batWidth >= WINDOW_WIDTH) {
			Bat.setPosition(WINDOW_WIDTH - batWidth, WINDOW_HEIGHT - 2 * batHeight);
		}
		Bat.move(0, BatSpeedX);
		BatSpeedX = 0;
		float ballX = ball.getPosition().x;
		float ballY = ball.getPosition().y;
		Vector2f  mid2{ ballX + BALL_RADIUS, ballY };
		Vector2f  mid1{ ballX , ballY + BALL_RADIUS };
		Vector2f midBottom{ ballX +BALL_RADIUS,  ballY + 2 * BALL_RADIUS };
		Vector2f midTop{ ballX + BALL_RADIUS,  ballY };

		if (pointInRect(Bat, mid1)) {
			ball_speedx = -ball_speedx;
		}
		if (pointInRect(Bat, midBottom)) {
			ball_speedy = -ball_speedy;
		}
		if (pointInRect(Bat, midTop)) {
			ball_speedy = -ball_speedy;
		}

		for (int i = 0; i < size; i++) {
			if (pointInRect(arr_rect[i], midBottom) || pointInRect(arr_rect[i], midTop)) {
				ball_speedy = -ball_speedy;
				arr_rect[i].move(0.f, down);
				PlayerScore++;
				PlayerScoreText.setString(std::to_string(PlayerScore));
				kol--;
			}
		}
		for (int i = 0; i < size; i++) {
			if (pointInRect(arr_rect2[i], midBottom) || pointInRect(arr_rect2[i], midTop)) {
				ball_speedy = -ball_speedy;
				arr_rect2[i].move(0.f, down);
				PlayerScore++;
				PlayerScoreText.setString(std::to_string(PlayerScore));
				kol--;
			}
		}
		for (int i = 0; i < size; i++) {
			if (pointInRect(arr_rect2[i], mid1)) {
				ball_speedy = -ball_speedy;
				arr_rect2[i].move(0.f, down);
				PlayerScore++;
				PlayerScoreText.setString(std::to_string(PlayerScore));
				kol--;
			}
		}
		for (int i = 0; i < size; i++) {
			if (pointInRect(arr_rect[i], mid1)) {
				ball_speedy = -ball_speedy;
				arr_rect[i].move(0.f, down);
				PlayerScore++;
				PlayerScoreText.setString(std::to_string(PlayerScore));
				kol--;
			}
		}
		for (int i = 0; i < size; i++) {
			if (pointInRect(arr_rect2[i], mid2)) {
				ball_speedy = -ball_speedy;
				arr_rect2[i].move(0.f, down);
				PlayerScore++;
				PlayerScoreText.setString(std::to_string(PlayerScore));
				kol--;
			}
		}
		for (int i = 0; i < size; i++) {
			if (pointInRect(arr_rect[i], mid2)) {
				ball_speedy = -ball_speedy;
				arr_rect[i].move(0.f, down);
				PlayerScore++;
				PlayerScoreText.setString(std::to_string(PlayerScore));
				kol--;
			}
		}
		if (kol <= 0) {
			window.close();
		}
		window.clear(sf::Color::Black);
		for (int i = 0; i < size; i++) {
			window.draw(arr_rect[i]);
		}
		for (int i = 0; i < size; i++) {
			window.draw(arr_rect2[i]);
		}
		window.draw(Bat);
		window.draw(ball);
		window.draw(PlayerScoreText);
		window.display();
	}
	return 0;
}