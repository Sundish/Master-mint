class canica{
	private:
		int color;

		/*El Color va de 1 a 4*/
		int validarColor(int c){
		    //Thins to add here
//		    char k;
//		    cout<<"letra"<<endl;
//		    cin>> k;
//		    cout<<k;
			if (c > 1 && c <= 6){
				return c;
			}else{
				return 1;
			}
		}
	public:
		int getColor(){
			return color;
		}
		void setColor(int c){
			color = validarColor(c);
		}
};
