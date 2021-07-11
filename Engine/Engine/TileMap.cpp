#include "framework.h"
#include "TileMap.h"

#include <fstream>

TileMap::TileMap(const string& tileMapFilePath, const Vector2u& tileSize, const vector<int>& tiles, const Vector2u& mapSize)
    :mapSize(mapSize), tileSize(tileSize), tiles(tiles)
{
	this->texture = new Texture;
	texture->loadFromFile(tileMapFilePath);

	vertices.setPrimitiveType(Quads);
	vertices.resize(mapSize.x * mapSize.y * 4);

    for (unsigned int i = 0; i < mapSize.x; ++i)
    {
        for (unsigned int j = 0; j < mapSize.y; ++j)
        {
            // get the current tile number
            int tileNumber = tiles.data()[i + j * mapSize.x];

            // find its position in the tileset texture
            int tu = tileNumber % (texture->getSize().x / tileSize.x);
            int tv = tileNumber / (texture->getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            Vertex* quad = &vertices[(i + j * mapSize.x) * 4];

            // define its 4 corners
            quad[0].position = Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }
}

void TileMap::SaveMap(const string& mapName)
{
    ofstream out(mapName, ios::binary);
    size_t size = tiles.size();
    out.write((const char*)&size, sizeof(size_t));

    out.write((const char*)&tiles.data()[0], sizeof(int) * size);

    out.close();
}

void TileMap::LoadMap(const string& mapName)
{
    ifstream in(mapName, ios::binary);

    tiles.clear();
    size_t size;
    in.read((char*)&size, sizeof(size_t));

    tiles.resize(size);

    in.read((char*)&tiles.data()[0], sizeof(int) * size);

    in.close();

    for (unsigned int i = 0; i < mapSize.x; ++i)
    {
        for (unsigned int j = 0; j < mapSize.y; ++j)
        {
            // get the current tile number
            int tileNumber = tiles.data()[i + j * mapSize.x];

            // find its position in the tileset texture
            int tu = tileNumber % (texture->getSize().x / tileSize.x);
            int tv = tileNumber / (texture->getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            Vertex* quad = &vertices[(i + j * mapSize.x) * 4];

            // define its 4 corners
            quad[0].position = Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }
}

void TileMap::Update(const Vector2f& mousePosition, int tileNumber)
{
    for (unsigned int i = 0; i < mapSize.x; ++i)
    {
        for (unsigned int j = 0; j < mapSize.y; ++j)
        {
            sf::Vertex* quad = &vertices[(i + j * mapSize.x) * 4];
            if ((mousePosition.x > quad[0].position.x && mousePosition.y > quad[0].position.y) &&
                (mousePosition.x < quad[1].position.x && mousePosition.y > quad[1].position.y) &&
                (mousePosition.x < quad[2].position.x && mousePosition.y < quad[2].position.y) &&
                (mousePosition.x > quad[3].position.x && mousePosition.y < quad[3].position.y))
            {

                tiles.data()[i + j * mapSize.x] = tileNumber;
                int tu = tileNumber % (texture->getSize().x / tileSize.x);
                int tv = tileNumber / (texture->getSize().x / tileSize.x);

                cout << "Click :" << tileNumber << "'s tile\n";

                quad[0].texCoords = Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

            }
        }
    }
}

void TileMap::draw(RenderTarget& target, RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = texture;
    target.draw(vertices, states);
}
