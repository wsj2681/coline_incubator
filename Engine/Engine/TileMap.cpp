#include "framework.h"
#include "TileMap.h"

TileMap::TileMap(const string& tileMapFilePath, const Vector2u& tileSize, const vector<int>& tiles, const Vector2u& mapSize)
{
	this->texture = new Texture;
	texture->loadFromFile(tileMapFilePath);

	vertices.setPrimitiveType(Quads);
	vertices.resize(mapSize.x * mapSize.y * 4);

    for (unsigned int i = 0; i < mapSize.x; ++i)
        for (unsigned int j = 0; j < mapSize.y; ++j)
        {
            // get the current tile number
            int tileNumber = tiles.data()[i + j * mapSize.x];

            // find its position in the tileset texture
            int tu = tileNumber % (texture->getSize().x / tileSize.x);
            int tv = tileNumber / (texture->getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * mapSize.x) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
}

void TileMap::draw(RenderTarget& target, RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = texture;
    target.draw(vertices, states);
}
