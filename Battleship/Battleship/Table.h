#ifndef TABLE_HEADER
#define TABLE_HEADER

using namespace std;

class Table
{
private:
	int rows = 10;
	int columns = 10;
	char matrix[10][10];

public:
	Table();
	~Table();

	void Clear();
	char SetOrientetion();
	bool CheckNeighbours(int x, int y);
	void SetShips();
	void ShowTable();
	bool checkPoint(int x, int y);
	void changePoint(int x, int y, char a);
	void ShowSecretTable();

};

#endif // !TABLE_HEADER
