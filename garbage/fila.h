
class fila{
	private:
		canica can[4];
		pista pis[4];
		pista val[4];
        int meco[4];
		void ordenarPista(pista p[4], int meco[4]){
			int uno = 0;
			int dos = 0;
			for(int i = 0; i<=3; i++){
				if(p[i].getColor()==2){
					dos++;
				}else if(p[i].getColor()==1){
					uno++;
				}
			}

			for(int i = 0; i<=3; i++){
				p[i].setColor(0);
			}
			for(int i = 0; i<dos; i++){
				p[i].setColor(2);
			}

			for(int i = dos; i<dos+uno; i++){
				p[i].setColor(1);
			}
			meco[0]=p[0].getColor();
			meco[1]=p[1].getColor();
			meco[2]=p[2].getColor();
			meco[3]=p[3].getColor();
			//cout << "pistas  de green son: " << meco[0] << "-" << meco[1] << "-" << meco[2] << "-" << meco[3] << endl << endl;
			//cout << "pistas  de blue son: " << p[0].getColor() << "-" << p[1].getColor() << "-" << p[2].getColor() << "-" << p[3].getColor() << endl << endl;
		}
	public:
		fila(){
			for(int i = 0; i<=3; i++){
				pis[i].setColor(0);
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

		bool validarFila(filaCodigo fc){
		    int meco[4];
		    int kaiser[4];
			canica r[4];
			fc.getCodigo(r);

			//Validar que sean la canica correcta en el lugar correcto
			for (int i = 0; i < 4; i++){
				if (can[i].getColor() == r[i].getColor()){
					pis[i].setColor(2);
					val[i].setColor(2);
				}
			}

			//Validar que sean la canica correcta en el lugar equivocado
			for (int i = 0; i < 4; i++){
				if(pis[i].getColor() == 0){
					for(int j = 0; j < 4; j++){
						if(val[j].getColor() == 0){
							if (can[i].getColor() == r[j].getColor()){
								pis[i].setColor(1);
								val[j].setColor(1);
								j = 5;
							}
						}
					}
				}
			}


			//Ordenar el arreglo de pistas
			ordenarPista(pis, meco);

			//cout << "pistas son: " << pis[0].getColor() << "-" << pis[1].getColor() << "-" << pis[2].getColor() << "-" << pis[3].getColor() << endl << endl;
			kaiser[0]=pis[0].getColor();
			kaiser[1]=pis[1].getColor();
			kaiser[2]=pis[2].getColor();
			kaiser[3]=pis[3].getColor();

			//cout<<kaiser[0]<<kaiser[1]<<kaiser[2]<<kaiser[3]<<endl;

			if(		pis[0].getColor() == 2
				 && pis[1].getColor() == 2
				 && pis[2].getColor() == 2
				 && pis[3].getColor() == 2){
				return true;
			}

			return false;
		}

    void impresionpistas(int meco[4]){
        //cout << "pistas  de red son: " << meco[0] << "-" << meco[1] << "-" << meco[2] << "-" << meco[3] << endl << endl;
        //cout << "pistas son: " << pis[0].getColor() << "-" << pis[1].getColor() << "-" << pis[2].getColor() << "-" << pis[3].getColor() << endl << endl;
    }
};
