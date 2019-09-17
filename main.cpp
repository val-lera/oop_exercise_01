/*
Блистунова Валерия М8О-201Б
---------------------------
Вариант 16. Создать класс Position для работы с географическими координатами.
Координаты задаются двуми числами широта и долгота. Долгота находится в диапазоне от -180 до 180 градусов.
Широта находится в диапазоне от -90 до 90 градусов.
Реализовать арифметические операции сложения, вычитания, умножения и деления, а также операции сравнения.
*/
#include<iostream>
using namespace std;
class Position
{
    public:
        double shirota, dolgota;
        void Add(Position a);
        void Sub(Position a);
        void Mul(int x);
        void Div(int y);
        void Compare(Position a);
        void Check();
};

void Position::Check(){
    if(dolgota < -180){
        dolgota = 180 + dolgota;
    }
    if(dolgota > 180){
        dolgota = 180 - dolgota;
    }
    if(shirota < -90){
        shirota = 90 + shirota;
    }
    if(shirota > 90){
        shirota = 90 - shirota;
    }
}
void Position::Add(Position b){
    shirota+=b.shirota;
    dolgota+=b.dolgota;
    Check();
    cout << dolgota << "   " << shirota << endl;
}
void Position::Sub(Position b){
    shirota-=b.shirota;
    dolgota-=b.dolgota;
    Check();
    cout << dolgota << "   " << shirota << endl;
}
void Position::Mul(int x){
    shirota*=x;
    dolgota*=x;
    while((dolgota < -180) || (dolgota > 180) || (shirota < -90) || (shirota > 90)) Check();
    cout << dolgota << "   " << shirota << endl;
}
void Position::Div(int y){
    if(y == 0){
        cout << "Ошибка. Деление на ноль" << endl;
    }
    else{
    shirota/=y;
    dolgota/=y;
    cout << dolgota << "   " << shirota << endl;
    }
}
void Position::Compare(Position b){
    if((shirota == b.shirota) && (dolgota == b.dolgota))
        cout << "Координаты точек одинаковы" << endl;
    else cout << "Координаты точек различны" << endl;
}

int main(){
    Position a,b;
    int user_command=1;
    int x, y;
    for(;;){
        if(user_command==1){
		    cout << "Введите число от 1 до 6 или 0 для действий: " << endl << 
							"1. Распечатать меню" << endl <<
							"2. Сложение координат" << endl <<
							"3. Вычетание координат" << endl <<
							"4. Умножение координат" << endl << 
							"5. Деление координат" << endl <<
							"6. Сравнение координат" << endl <<
							"0. Выход из программы" << endl;
		}
        else if(user_command==2){
            cout << "Введите долготу и широту первой точки: " << endl; 
            cin >> a.dolgota >> a.shirota;
            cout << "Введите долготу и широту второй точки: " << endl;
            cin >> b.dolgota >> b.shirota;
            a.Add(b);
        }
        else if(user_command==3){
            cout << "Введите долготу и широту первой точки: " << endl;
            cin >> a.dolgota >> a.shirota;
            cout << "Введите долготу и широту второй точки: " << endl;
            cin >> b.dolgota >> b.shirota;
            a.Sub(b);
        }
        else if(user_command==4){
            cout << "Введите долготу и широту точки: " << endl;
            cin >> a.dolgota >> a.shirota;
            cout << "Введите число: " << endl;
            cin >> x;
            a.Mul(x);
        }
        else if(user_command==5){
            cout << "Введите долготу и широту точки: " << endl;
            cin >> a.dolgota >> a.shirota;
            cout << "Введите число: " << endl;
            cin >> y;
            a.Div(y);
        }
        else if(user_command==6){
            cout << "Введите долготу и широту первой точки: " << endl;
            cin >> a.dolgota >> a.shirota;
            cout << "Введите долготу и широту второй точки: " << endl;
            cin >> b.dolgota >> b.shirota;
            a.Compare(b);
        }
        else if(user_command == 0) 
            break;
        else 
            cout << "Нет такого пункта меню" << endl;
        cout << "Введите номер пункта меню > " << endl; 
		cin >> user_command;
    }
    return 0;
}