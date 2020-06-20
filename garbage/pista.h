//2 representa lugar exacto, 1 color correcto mas lugar equivocado, 0 estas pendejo
class pista{
	private:
		int color;


		/*El Color va de 0 a 2*/
		int validarColor(int c){
			if (c > 0 && c <= 2){
				return c;
			}else{
				return 0;
			}
		}
	public:
		//CONSTRUCT
		pista(){
			color = 0;
		}

		int getColor(){
			return color;
		}
		void setColor(int c){
			color = validarColor(c);
		}
};
