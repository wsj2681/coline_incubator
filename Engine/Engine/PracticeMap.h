#pragma once

class Object;

class PracticeMap : public Drawable, public Transformable
{
public:
	PracticeMap() = default;
	PracticeMap(const string& tileSetFilePath, const Vector2u& tileSize, const vector<int>& tiles, const Vector2u& mapSize);
	PracticeMap(const PracticeMap&) = delete;
	PracticeMap& operator=(const PracticeMap&) = delete;
	~PracticeMap() = default;

private:

	// TileSet : Ÿ�� �ؽ��� �̹���
	Texture* tileSet = nullptr;

	// Ÿ�ϵ��� ������ ��Ƴ��� �����̳�
	VertexArray vertices;

	Vector2u tileSize;
	Vector2u mapSize;

	// Ÿ���� ��ȣ�� ��Ƴ��� �����̳�
	vector<int> tiles;

	IntRect imageRect;

private:

	void InitVertices();

public:

	void Update(const Vector2f& mousePosition, int tileNumber);
	void Update(Object* object);

	const IntRect& GetTile(int tileNumber);

	void SaveMap(const string& mapName);
	void LoadMap(const string& mapName);

	virtual void draw(RenderTarget& target, RenderStates states) const;

};

