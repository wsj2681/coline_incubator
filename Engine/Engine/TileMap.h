#pragma once
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
	VertexArray vertices{};

public:

	virtual void draw(RenderTarget& target, RenderStates states) const;

};

