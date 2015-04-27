#pragma once

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int controlPanelWidth = 200;
const int gridDisplaySize = 600;

const int buttonSize = 100;

const sf::FloatRect controlPanelRect(SCREEN_WIDTH - controlPanelWidth, 0, controlPanelWidth, SCREEN_HEIGHT);
const float controlPanelSize = (float)controlPanelWidth / SCREEN_WIDTH;

const sf::FloatRect controlPanelViewport(1 - controlPanelSize, 0, controlPanelSize, 1);

static int LEVELSIZE = 10;