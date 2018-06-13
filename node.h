
// перечисление возможных типов данных для узла, используется в конструкторе (расширяемо)
enum Type{enumUserData, enumShape, enumAdvancedUserData};

//структуры - типы данных доступные для хранения в узлах (расширяемо)
struct UserData
{
	char* nodeName;
	char* userName;
	int id;
};

struct Point
{
	int x;
	int y;
};
struct Shape
{
	//const int n=10;
	char*  nodeName;
	char*  shapeName;
	Point points[10];
};



struct AdvancedUserData
{
	char* nodeName;
	char* userName;
	int id;
	int age;
	int children;
	float weight;
};

class Node
{
private:
    long addr;
    Type t;
    Node* left;
    Node* right;
    Node* parent;
public:

	//геттеры для получения всей структуры с данными из узла (расширяемо)
	UserData* getUserData();
    Shape* getShape();
    AdvancedUserData* getAdvancedUserData();

    void setUserData(UserData*);
    void setShape(Shape*);
    void setAdvancedUserData(AdvancedUserData*);

	Type getType();

    Node* getParent();
    void setParent(Node*);
    Node* getRight();
  //  void setRight(Node*);
    //void setLeft(Node*);
    Node* getLeft();
    bool canAddChild();
    void addChild(Node*);
    int getChildrenCount();
    int getTotalChildrenCount();
    void showInfo();
    int distanceToRoot();
    Node* getRoot();


 
    Node(Type, Node*);
   // Node(long=0,Type=UserData,Node* = 0,Node* =0,Node* =0);

};
