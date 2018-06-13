#include "node.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


int main() {

    //указатель на текущий узел для перемещения по дереву
    Node* current;

    //инициализация корневого узла
    Node* root = new Node(enumShape,0);
    cout<<"Корень создан! урара"<<endl;
    cout<<"тип корня:"<<root->getType()<<endl;
    cout<<"Корень создан! урара"<<endl;

    //root->showInfo();

    //указатель текущего узла ставим на root
    current = root;

    //временные структуры для заполнения узлов
    Point points[10] = {{1,3},{2,4},{3,5},{4,6},{5,7},{6,8},{7,9},{8,10},{9,11},{10,12}};

    UserData*             temptype0 = new UserData{"Данные пользователя","Я пользователь!",123};
    Shape*                temptype1 = new Shape{"Узел с формой","Безымянная", {{1,3},{2,4},{3,5},{4,6},{5,7},{6,8},{7,9},{8,10},{9,11},{10,12}} };
    AdvancedUserData*     temptype2 = new AdvancedUserData{"Расширенные данные пользователя", "Игорь Кузин", 24680, 25, 4, 80.2};


    //заполняем корень данными типа Shape
    root->setShape(temptype1);


    cout<<"данные в корне:"<<endl;
    cout<<"строка1:"<<root->getUserData()->nodeName<<endl<<"строка2:"<<root->getShape()->shapeName<<endl
    <<"целочисленный тип1:"<<root->getUserData()->id<<endl;

    //создание двух потомков от корня + заполнение их значениями
    Node* element = new Node(enumUserData,0);
    element->   setParent(root);
    root->      addChild(element);
    element->   setUserData(temptype0);

    element = new Node(enumAdvancedUserData,0);
    element->   setParent(root);
    root->      addChild(element);
    element->   setAdvancedUserData(temptype2);


    //создание дополнительной ветки на правом листе (3й уровень)
    element=new Node(enumUserData,0);
    element->   setParent(root->getRight());
    root->      getRight()->addChild(element);
    root->      getRight()->getLeft()->setUserData(new UserData{"Последний лист","Дядя боря", 222});
   
    //--------------------------------временное смещение в лист! 
    current = root->getRight()->getLeft();

    cout<<"дети корня:"<<root->getChildrenCount()<<endl;

    cout<<"левое дитя корня(тип):"<<root->getLeft()->getType()<<endl;
    cout<<"правое дитя корня(тип):"<<root->getRight()->getType()<<endl;

    cout<<"Общее число потомков:"<<root->getTotalChildrenCount()<<endl;

    string str = "";
    while(true)
    {
        printf("-------\n");
        printf("Текущий узел:");
        if(current->getChildrenCount()==0) 
            printf("[Лист]\n");
        else if(!current->getParent()) 
            printf("[Корень]\n");
        else
            printf("[Ветвь]\n");
        printf("-------\n");

        switch(current->getType())
        {
            case(0):
                
                printf("Тип: %d\n", current->getType());
                printf("Имя узла: %s\n", current->getUserData()->nodeName);
                printf("Имя Пользователя: %s\n", current->getUserData()->userName);
                printf("Идентификатор: %d\n",  current->getUserData()->id);
            break;
            case(1):
                printf("Тип: %d\n", current->getType());
                printf("Имя узла: %s\n", current->getShape()->nodeName);
                printf("Название формы: %s\n", current->getShape()->shapeName);
                printf("Массив точек:\n");
                for(int i=0; i<10; i++)
                 {
                  
                        cout<<current->getShape()->points[i].x<<":"<<current->getShape()->points[i].y<<endl;
                 }


            break;
            case(2):
                printf("Тип: %d\n", current->getType());
                printf("Имя узла: %s\n", current->getAdvancedUserData()->nodeName);
                printf("Имя Пользователя: %s\n", current->getAdvancedUserData()->userName);
                printf("Идентификатор: %d\n",  current->getAdvancedUserData()->id);
                printf("Возраст: %d\n",  current->getAdvancedUserData()->age);
                printf("Кол-во детей: %d\n",  current->getAdvancedUserData()->children);
                printf("Вес: %f\n",  current->getAdvancedUserData()->weight);
            break;
        }
        cout<<"Комманды:(toleft) (toright) (toparent) (toroot) (info) (exit)"<<endl;
        cout << "Ввод: "<<endl;
        cin  >> str;

        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

            if(str == "exit") return 0;
            
            if(str == "toleft")
                if(current->getLeft())
                {
                    current=current->getLeft();
                    cout<<"[ПЕРЕХОД К ЛЕВОМУ ПОТОМКУ]"<<endl;
                }
                else
                cout<<"левого потомка нет. Остались на месте"<<endl;

            if(str == "toright")
                if(current->getRight())
                {
                    current = current->getRight();
                    cout<<"[ПЕРЕХОД К ПРАВОМУ ПОТОМКУ]"<<endl;
                }
                else
                cout<<"правого потомка нет. Остались на месте"<<endl;

            if(str == "toparent")
                if(current->getParent())
                {
                    current=current->getParent();
                    cout<<"[ПЕРЕХОД К РОДИТЕЛЬСКОМУ УЗЛУ]"<<endl;
                }
                else
                cout<<"родительского узла нет (это корень)."<<endl;

            if(str == "toroot")
            {
                current = current->getRoot();
                cout<<"[ПЕРЕХОД К КОРНЕВОМУ УЗЛУ]"<<endl;             
            }
            if(str == "info")
            {
                cout<<"------------------СВОДКА--------------------------"<<endl;
                cout<<"Общее количество узлов:"<<current->getRoot()->getTotalChildrenCount()+1<<endl;
                cout<<"расстояние до корня:"<<current->distanceToRoot()<<" узлов"<<endl;
                cout<<"Общее количество потомков от текущего:"<<current->getTotalChildrenCount()<<endl;
                cout<<"--------------------------------------------------"<<endl;
            }
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    
        }

    

    return 0;
}
