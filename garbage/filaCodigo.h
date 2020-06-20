class filaCodigo{
	private:
		canica can[4];
	public:
		void setCodigo(){
			for(int i = 0; i<=3; i++){
				can[i].setColor(1+rand()%7);
			}
		}
		void setCodigo(int a, int b, int c, int d){
			can[0].setColor(a);
			can[1].setColor(b);
			can[2].setColor(c);
			can[3].setColor(d);
		}
		void getCodigo(canica c[4]){
			for(int i = 0; i<=3; i++){
				c[i] = can[i];
			}
		}

		filaCodigo(){
		    int op=0, cacerola=0;
            cout<<"Desea asignar un codigo o jugar en automatico(1-asignar/ 2 - automatico)?"<<endl;
            cin>>op;
            if(op==1){
                 cout<< "a - rojo, b - negro, c - verde, d - morado, e - amnarillo, f - naranja" <<endl;
                char kas='a',kbs='a',kcs='a',kds='a';
                int a=0, b=0, c=0, d=0;
                scanf(" %c", &kas);
                    switch(kas){
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
                setCodigo(a,b,c,d);
                cout<<"El codigo secreto es: "<<can[0].getColor()<<"-"<<can[1].getColor()<<"-"<<can[2].getColor()<<"-"<<can[3].getColor()<<endl;
            }else{
                char perro='v',vaca='v',oveja='v',gei='v';
                setCodigo();
            cout<<"El codigo secreto es: "<<can[0].getColor()<<"-"<<can[1].getColor()<<"-"<<can[2].getColor()<<"-"<<can[3].getColor()<<endl;//Codigo secreto
            switch(can[0].getColor()){
                        case 1: perro='a';
                        break;
                        case 2: perro='b';
                        break;
                        case 3: perro='c';
                        break;
                        case 4: perro='d';
                        break;
                        case 5: perro='e';
                        break;
                        case 6: perro='f';
                        break;

                    }
             switch(can[1].getColor()){
                        case 1: vaca='a';
                        break;
                        case 2: vaca='b';
                        break;
                        case 3: vaca='c';
                        break;
                        case 4: vaca='d';
                        break;
                        case 5: vaca='e';
                        break;
                        case 6: vaca='f';
                        break;

                    }
              switch(can[2].getColor()){
                        case 1: oveja='a';
                        break;
                        case 2: oveja='b';
                        break;
                        case 3: oveja='c';
                        break;
                        case 4: oveja='d';
                        break;
                        case 5: oveja='e';
                        break;
                        case 6: oveja='f';
                        break;

                    }
            switch(can[3].getColor()){
                        case 1: gei='a';
                        break;
                        case 2: gei='b';
                        break;
                        case 3: gei='c';
                        break;
                        case 4: gei='d';
                        break;
                        case 5: gei='e';
                        break;
                        case 6: gei='f';
                        break;

                    }
            cout<<"El codigo secreto es: "<<perro<<"-"<<vaca<<"-"<<oveja<<"-"<<gei<<endl;
//////////////////////////////////////////////
            }

		}

};
