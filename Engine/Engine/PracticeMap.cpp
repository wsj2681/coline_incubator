#include "framework.h"
#include "PracticeMap.h"
#include "JumpObject.h"

PracticeMap::PracticeMap(const string& tileSetFilePath, const Vector2u& tileSize, const vector<int>& tiles, const Vector2u& mapSize)
	:tiles(tiles), tileSize(tileSize), mapSize(mapSize)
{
	tileSet = new Texture;
	tileSet->loadFromFile(tileSetFilePath);

	// 타일은 사각형으로 만들것이기 때문에
	vertices.setPrimitiveType(Quads);

	// 정점의 갯수를 미리 정해준다.
	vertices.resize(mapSize.x * mapSize.y * 4);

	InitVertices();
}

void PracticeMap::InitVertices()
{
	for (unsigned int i = 0; i < mapSize.x; ++i)
	{
		for (unsigned int j = 0; j < mapSize.y; ++j)
		{
			int tileNumber = tiles.data()[i + j * mapSize.x];

			Vertex* quad = &vertices[(i + j * mapSize.x) * 4];

			float tileX = (float)tileSize.x;
			float tileY = (float)tileSize.y;

			int texU = tileNumber % (tileSet->getSize().x / tileSize.x);
			int texV = tileNumber / (tileSet->getSize().x / tileSize.x);

			// 좌 상단
			quad[0].position = Vector2f(i * tileX, j * tileY);

			// 우 상단
			quad[1].position = Vector2f((i + 1) * tileX, j * tileY);

			// 우 하단
			quad[2].position = Vector2f((i + 1) * tileX, (j + 1) * tileY);

			// 좌 하단
			quad[3].position = Vector2f(i * tileX, (j + 1) * tileY);

			// 텍스쳐에 대한 텍스코드를 정해준다.
			quad[0].texCoords = Vector2f(texU * tileX, texV * tileY);
			quad[1].texCoords = Vector2f((texU + 1) * tileX, texV * tileY);
			quad[2].texCoords = Vector2f((texU + 1) * tileX, (texV + 1) * tileY);
			quad[3].texCoords = Vector2f(texU * tileX, (texV + 1) * tileY);

		}
	}
}

void PracticeMap::Update(const Vector2f& mousePosition, int tileNumber)
{
	for (unsigned int i = 0; i < mapSize.x; ++i)
	{
		for (unsigned int j = 0; j < mapSize.y; ++j)
		{
			Vertex* quad = &vertices[(i + j * mapSize.x) * 4];

			if ((mousePosition.x > quad[0].position.x && mousePosition.y > quad[0].position.y) &&
				(mousePosition.x < quad[1].position.x && mousePosition.y > quad[1].position.y) &&
				(mousePosition.x < quad[2].position.x && mousePosition.y < quad[2].position.y) &&
				(mousePosition.x > quad[3].position.x && mousePosition.y < quad[3].position.y))
			{
				tiles.data()[i + j * mapSize.x] = tileNumber;

				float tileX = (float)tileSize.x;
				float tileY = (float)tileSize.y;

				int texU = tileNumber % (tileSet->getSize().x / tileSize.x);
				int texV = tileNumber / (tileSet->getSize().x / tileSize.x);

				// 텍스쳐에 대한 텍스코드를 정해준다.
				quad[0].texCoords = Vector2f(texU * tileX, texV * tileY);
				quad[1].texCoords = Vector2f((texU + 1) * tileX, texV * tileY);
				quad[2].texCoords = Vector2f((texU + 1) * tileX, (texV + 1) * tileY);
				quad[3].texCoords = Vector2f(texU * tileX, (texV + 1) * tileY);
			}
		}
	}
}

void PracticeMap::Update(Object* object)
{
	for (unsigned int j = 0; j < mapSize.y; ++j)
	{
		for (unsigned int i = 0; i < mapSize.x; ++i)
		{
			sf::Vertex* quad = nullptr;
			quad = &vertices[(i + j * mapSize.x) * 4];
			Vector2f objectPosition = object->getPosition();
			Vector2f dir = dynamic_cast<JumpObject*>(object)->GetDirection();

			if (dir.x != 0.f || dir.y != 0.f)
			{
				if (dir.x > 0.f)
				{
					if ((objectPosition.x > quad[0].position.x + 16 && objectPosition.y > quad[0].position.y) &&
						(objectPosition.x < quad[1].position.x		&& objectPosition.y > quad[1].position.y) &&
						(objectPosition.x < quad[2].position.x		&& objectPosition.y < quad[2].position.y) &&
						(objectPosition.x > quad[3].position.x + 16 && objectPosition.y < quad[3].position.y))
					{
						if (tiles.data()[(i + 1) + j * mapSize.x] == 111)
						{
							dynamic_cast<JumpObject*>(object)->SetDirection(-dir);
						}
					}
				}
				else if (dir.x < 0.f)
				{
					if ((objectPosition.x > quad[0].position.x		&& objectPosition.y > quad[0].position.y) &&
						(objectPosition.x < quad[1].position.x - 16 && objectPosition.y > quad[1].position.y) &&
						(objectPosition.x < quad[2].position.x - 16 && objectPosition.y < quad[2].position.y) &&
						(objectPosition.x > quad[3].position.x		&& objectPosition.y < quad[3].position.y))
					{
						if (tiles.data()[(i - 1) + j * mapSize.x] == 111)
						{
							dynamic_cast<JumpObject*>(object)->SetDirection(-dir);
						}
					}
				}
				else if (dir.y > 0.f)
				{
					if ((objectPosition.x > quad[0].position.x && objectPosition.y > quad[0].position.y + 16) &&
						(objectPosition.x < quad[1].position.x && objectPosition.y > quad[1].position.y + 16) &&
						(objectPosition.x < quad[2].position.x && objectPosition.y < quad[2].position.y) &&
						(objectPosition.x > quad[3].position.x && objectPosition.y < quad[3].position.y))
					{
						if (tiles.data()[i + (j + 1) * mapSize.x] == 111)
						{
							dynamic_cast<JumpObject*>(object)->SetDirection(-dir);
						}
					}
				}
				else if (dir.y < 0.f)
				{
					if ((objectPosition.x > quad[0].position.x && objectPosition.y > quad[0].position.y) &&
						(objectPosition.x < quad[1].position.x && objectPosition.y > quad[1].position.y) &&
						(objectPosition.x < quad[2].position.x && objectPosition.y < quad[2].position.y - 16) &&
						(objectPosition.x > quad[3].position.x && objectPosition.y < quad[3].position.y - 16))
					{
						if (tiles.data()[i + (j - 1) * mapSize.x] == 111)
						{
							dynamic_cast<JumpObject*>(object)->SetDirection(-dir);
						}
					}
				}
			}
		}
	}
}

const IntRect& PracticeMap::GetTile(int tileNumber)
{
	int count = 0;
	for (unsigned int i = 0; i < tileSet->getSize().y; i += tileSize.y)
	{
		for (unsigned int j = 0; j < tileSet->getSize().x; j += tileSize.x)
		{
			if (count == tileNumber)
			{
				imageRect = IntRect(j, i, 32, 32);
				return imageRect;
			}

			count++;
		}
	}


	return IntRect();
}

void PracticeMap::SaveMap(const string& mapName)
{
	ofstream out(mapName, ios::binary);

	int size = tiles.size();
	
	out.write((const char*)&size, sizeof(int));

	// 4바이트 곱하기 8바이트를 하면 산술 오버플로우가 일어날 수 있으므로
	// 크기가 작은 자료형의 자료형을 큰 자료형과 맞춰준다.
	out.write((const char*)&tiles.data()[0], sizeof(int) * static_cast<__int64>(size));

	out.close();
}

void PracticeMap::LoadMap(const string& mapName)
{
	ifstream in(mapName, ios::binary);

	tiles.clear();
	int size;

	in.read((char*)&size, sizeof(int));

	tiles.resize(size);

	in.read((char*)&tiles.data()[0], sizeof(int) * static_cast<__int64>(size));

	in.close();

	InitVertices();

}

void PracticeMap::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = tileSet;

	target.draw(vertices, states);
}
