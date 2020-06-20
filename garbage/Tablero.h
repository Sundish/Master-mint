
class tablero{
private:
     filaCodigo fc;
     fila f[10];
     bool ganado = false;
public:
     tablero()
          {
               //Define la clave a desifrar
               //cout << "BIENVENIDO A MASTER MIND" << endl << endl;
               cout << "Ya generamos la clave" << endl;
               cout << "tienes 10 intentos" << endl;
               cout << "Genera una combinacion de 4 colores (1-6) para decifrarla" << endl << endl;
               cout << "Ingresa los numeros separados por espacio" << endl << endl;
          }
     void jugar()
          {
               for(int i = 0; i < 10; i++)
               {
                    int a=0, b=0, c=0, d=0;
                    int cacerola=0;
                    char kas='a',kbs='a',kcs='a',kds='a';
                    cout<<"ingrese lo colores de canicas"<<endl;
                    cin>>kas;
                    switch(kas)
                    {
                    case 'a': cacerola=1;
                         break;
                    case 'b': cacerola=2;
                         break;
                    case 'c': cacerola=3;
                         break;
                    case 'd': cacerola=4;
                         break;
                    case 'e': cacerola=5;
                         break;
                    case 'f': cacerola=6;
                         break;
                    default: cin>>kas;
                    }
                    a=cacerola;
                    cin>>kbs;
                    switch(kbs){
                    case 'a': cacerola=1;
                         break;
                    case 'b': cacerola=2;
                         break;
                    case 'c': cacerola=3;
                         break;
                    case 'd': cacerola=4;
                         break;
                    case 'e': cacerola=5;
                         break;
                    case 'f': cacerola=6;
                         break;
                    default: cin>>kbs;
                    }
                    b=cacerola;
                    cin>>kcs;
                    switch(kcs){
                    case 'a': cacerola=1;
                         break;
                    case 'b': cacerola=2;
                         break;
                    case 'c': cacerola=3;
                         break;
                    case 'd': cacerola=4;
                         break;
                    case 'e': cacerola=5;
                         break;
                    case 'f': cacerola=6;
                         break;
                    default: cin>>kcs;
               }
                    c=cacerola;
                    cin>>kds;
                    switch(kds){
                    case 'a': cacerola=1;
                         break;
                    case 'b': cacerola=2;
                         break;
                    case 'c': cacerola=3;
                         break;
                    case 'd': cacerola=4;
                         break;
                    case 'e': cacerola=5;
                         break;
                    case 'f': cacerola=6;
                         break;
                    default: cin>>kds;
                    }
                    d=cacerola;
//				cin >> a;
//				cin >> b;
//				cin >> c;
//				cin >> d;

                    //Poner el código por parte del Jugador
                    f[i].setCodigo(a, b, c, d);
                    //cout<<"El codigo usuario es: "<<can[0].getColor()<<"-"<<endl;
                    //Validar el código del jugador contra el código clave
                    if(f[i].validarFila(fc)){
                         ganado = true;
                         i = 10;
                    }
               }
               if(ganado){
                    cout << "FELICIDADES... DESCIFRASTE EL CODIGO!!!" << endl << endl;
               } else {
                    cout << "QUE PENA... SE TE ACABARON LAS OPORTUNIDADES... SUERTE EN LA PROXIMA" << endl << endl;
               }
          }
};
