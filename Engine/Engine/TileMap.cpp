#include "framework.h"
#include "TileMap.h"
#include "Object.h"

TileMap::TileMap(const string& tileMapFilePath, const Vector2u& tileSize, const vector<int>& tiles, const Vector2u& mapSize)
    :mapSize(mapSize), tileSize(tileSize), tiles(tiles)
{
    this->texture = new Texture;
    texture->loadFromFile(tileMapFilePath);

	vertices.setPrimitiveType(Quads);
	vertices.resize(mapSize.x * mapSize.y * 4);

    SetVertices();
}

void TileMap::SetVertices()
{
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

            float tileX = (float)tileSize.x;
            float tileY = (float)tileSize.y;
            // define its 4 corners
            quad[0].position = Vector2f(i * tileX, j * tileY);
            quad[1].position = Vector2f((i + 1) * tileX, j * tileY);
            quad[2].position = Vector2f((i + 1) * tileX, (j + 1) * tileY);
            quad[3].position = Vector2f(i * tileX, (j + 1) * tileY);

            // define its 4 texture coordinates
            quad[0].texCoords = Vector2f(tu * tileX, tv * tileY);
            quad[1].texCoords = Vector2f((tu + 1) * tileX, tv * tileY);
            quad[2].texCoords = Vector2f((tu + 1) * tileX, (tv + 1) * tileY);
            quad[3].texCoords = Vector2f(tu * tileX, (tv + 1) * tileY);
        }
    }
}

const IntRect& TileMap::GetTile(int tileType)
{
    int Count = 0;

    for (unsigned int y = 0; y < texture->getSize().y; y += tileSize.y)
    {
        for (unsigned int x = 0; x < texture->getSize().x; x += tileSize.x)
        {
            if (Count == tileType)
            {
                imageRect = IntRect(x, y, 32, 32);
                return imageRect;
            }
            Count++;
        }
    }
    
    return IntRect();
}

void TileMap::SaveMap(const string& mapName)
{
    ofstream out(mapName, ios::binary);
    int size = tiles.size();
    out.write((const char*)&size, sizeof(int));

    out.write((const char*)&tiles.data()[0], sizeof(int) * static_cast<__int64>(size));

    out.close();
}

void TileMap::LoadMap(const string& mapName)
{
    ifstream in(mapName, ios::binary);

    tiles.clear();
    int size;
    in.read((char*)&size, sizeof(int));

    tiles.resize(size);

    in.read((char*)&tiles.data()[0], sizeof(int) * static_cast<__int64>(size));

    in.close();

    SetVertices();
}

void TileMap::Update(const Vector2f& mousePosition, int tileNumber)
{
    int tileIndex = 0;
    for (unsigned int j = 0; j < mapSize.y; ++j)
    {
        for (unsigned int i = 0; i < mapSize.x; ++i)
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

                float tileX = (float)tileSize.x;
                float tileY = (float)tileSize.y;

                //cout << "Click " << j << "," << i << "'s Tile,  Changed " << tileNumber << endl;

                quad[0].texCoords = Vector2f(tu * tileX, tv * tileY);
                quad[1].texCoords = Vector2f((tu + 1) * tileX, tv * tileY);
                quad[2].texCoords = Vector2f((tu + 1) * tileX, (tv + 1) * tileY);
                quad[3].texCoords = Vector2f(tu * tileX, (tv + 1) * tileY);

            }
            tileIndex++;
        }
    }
}

void TileMap::draw(RenderTarget& target, RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = texture;
    target.draw(vertices, states);
}
