#pragma once

class Object;


class TileMap final : public Drawable, public Transformable
{
public:
	TileMap() = default;
	TileMap(const string& tileMapFilePath, const Vector2u& tileSize, const vector<int>& tiles, const Vector2u& mapSize);
	TileMap(const TileMap&) = delete;	
	TileMap& operator=(const TileMap&) = delete;
	~TileMap() = default;

private:

	Texture* texture = nullptr;
	VertexArray vertices;
	VertexArray baseVertices;

	Vector2u mapSize{ 0, 0 };
	Vector2u tileSize{ 0, 0 };
	vector<int> tiles;

	// MouseCursor image
	IntRect imageRect;

	Vertex* CollideBox = nullptr;
	FloatRect MapBounds{};

	int nowCharacterTile = 0;

private:

	void SetVertices();

public:

	const IntRect& GetTile(int tileType);
	const int& GetTileNumberInPosition(const Vector2f& position);

	FloatRect& GetMapBounds();
	void SaveMap(const string& mapName);
	void LoadMap(const string& mapName);

	void Update(const Vector2f& mousePosition, int tileNumber, bool BaseTile = false);

	virtual void draw(RenderTarget& target, RenderStates states) const;

};

