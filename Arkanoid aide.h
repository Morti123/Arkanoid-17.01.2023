#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 60.f;

const float batWidth = 80.f;
const float batHeight = 20.f;
const float batHeight2 = 50.f;
const float batOffset = 50.f;
const float batSpeed = 5.f;
const int charSize = 64;
const float down = 900.f;
const float BALL_RADIUS = 25.f;
float kol = 20;
const size_t size = 10;

const sf::Color BatColor{ sf::Color::White };
const sf::Color BALL_COLOR{ sf::Color::White };

const sf::Vector2f ballStartPos{ (WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,
  (WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2};
const sf::Vector2f BatStartPos{ (WINDOW_WIDTH - 3 * batWidth) / 2, WINDOW_HEIGHT - 2 * batHeight };
const sf::Vector2f TextStartPos{ 20.f, 3.f };
const sf::Vector2f batSize(80.f, 20.f);

 


