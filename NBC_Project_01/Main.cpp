#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "Zoo.h"
#include "Cat.h"
#include "Cow.h"
#include "Dog.h"

Animal* createRandomAnimal()
{
    Animal* newAnimal;

    switch (rand() % 3)
    {
    case 0:
        newAnimal = new Cat();
        cout << "����̰� �߰��Ǿ����ϴ�." << endl;
        break;
    case 1:
        newAnimal = new Cow();
        cout << "�Ұ� �߰��Ǿ����ϴ�." << endl;
        break;
    case 2:
        newAnimal = new Dog();
        cout << "�������� �߰��Ǿ����ϴ�." << endl;
        break;
    default:
        newAnimal = nullptr;
    }

    return newAnimal;
}

int main()
{
    srand((unsigned int)time(NULL));
    Zoo* mainZoo = new Zoo();
    int count, maxCount = 10;
    char Input;
    cout << "1. ���� �߰�\t2. ���� �ҷ�����\tAnykey. ����" << endl;
START:
    Input = _getch();

    system("cls");

    switch (Input - 48)
    {
    case 1:
        cout << "�� ������ �߰��ϰڽ��ϱ�? (�ִ� " << maxCount - mainZoo->GetCount() << "����) : ";
        cin >> count;
        if (count > maxCount - mainZoo->GetCount())
        {
            cout << "�ִ밪�� �Ѿ����ϴ�. �ʱ� ȭ������ ���ư��ϴ�." << endl;
            break;
        }
        for(int i = 0; i < count; i++)
            mainZoo->addAnimal(createRandomAnimal());
        break;
    case 2:
        mainZoo->performActions();
        break;
    case 3:
        mainZoo->~Zoo();
        return 0;
    default:
        cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
        break;
    }

    cout << "1. ���� �߰�\t2. ���� �ҷ�����\t3. ����" << endl;
    goto START;

    return 0;
}