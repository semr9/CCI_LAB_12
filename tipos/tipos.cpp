#include <iostream>
#include <string>
using namespace std;
//Declaramos en cada clase el uso de priavte,protected y public
class aviones
{
    private:
    	int serie;
    	int fecha;
    protected:
        int numero_de_venta;
        string marca;
    public:
        aviones(int a, const string &b)
                :numero_de_venta(a),marca(b){}
        int get_venta() const
        {
            return numero_de_venta;
        }
        const string &get_marca() const
        {
            return marca;
        }
        //utilizamos estas funciones para poder ingresar datos a la parte de private 
        //ya que de otra manera nos e podria
        void setserie(int a){serie=a;}       
		void setfecha(int b){fecha=b;}
		//utilizamos estas funciones para poder retornar  datos de la parte de private 
		int getserie(){return serie;}
		int getfecha(){return fecha;}
};
//para evitar el problema de amiguo , utilizamos virtual
class avion_a : virtual public  aviones//cuando heredamos , podemos heredar todo menos lo de private
{
    private:
    	int dia;
    protected:
        string fabricacion;
    public:
        avion_a(int a, const string &b,const string &c)
               :aviones(a,b),fabricacion(c){}
        string get_fabricacion() const
        {
            return fabricacion;
        }
		void setdia(int a){dia=a;}
		int getdia(){return dia;}


};

class avion_b : virtual public  aviones
{
	private:
    	int materiales;
    protected:
        int motores;
    public:
        avion_b(int a, const string &b,int c)
                :aviones(a,b),motores(c){}
        int get_motores() const
        {
           return  motores;
        }
        void setmateriales(int a){materiales=a;}
		int getmateriales(){return materiales;}
		

};
class monitoreo:  public avion_a ,public avion_b //heredamos todas las caractersticas de nuestras anterores clases que pertenecen a public  y protected
{
    private:
    	int salidas;
    protected:
        string destino;
    public:
    	monitoreo(int a, const string &b,int c, const string &d,int e,const string &f ,const string &g)
               :aviones(a,b),avion_a(e,d,f),avion_b(a,b,c),destino(g){}
        const string &getdestino() {return  destino;}
		void setsalidas(int a){salidas=a;}
		int getsalidas(){return salidas;}
};

int main()
{	
	//Inicializamos nuestra clase que ha heredados de aviones , avion_a y avion_b
	monitoreo uno(32,"aleman",34,"x112",45,"PQ-45","HK-78");	
	//Demostarmos como podemos accesar mediante public a nuestros atributos
	//TAmbien demostramos a la vez como conseguimos imprimir nuestros datos que estan en protected ya que se heredan en clase pero no se pueden accesar mediante el usuario
	//Para probar que podemos accesar a la get_marca que es un atributo de aviones, y esta en public utilizamso 
    string a=uno.get_marca();
    cout<<"marca::\n";
    cout<<a<<"\n";
    //Para probar que podemos accesar a la get_fabricaion que es un atributo de avion_a, y esta en public utilizamso
 	string b=uno.get_fabricacion();   
    cout<<"fabricacion::\n";
    cout<<b<<"\n";
    //Para probar que podemos accesar a la get_motores que es un atributo de avion_b, y esta en public utilisamos
 	int c=uno.get_motores();   
    cout<<"numero de motores::\n";
    cout<<c<<"\n";
    
    //Demostarmaos como podemos accesar a nuestros caracteristicas privadas mediante funciones , como si fueran un disfraz
    //damos un valor a nuestra caracteristica prvada y luego la mprimimo
    //Hacemso esto con cada atributo de las clases heredadas
    uno.setmateriales(45);
    cout<<"materiales::\n";
    cout<<uno.getmateriales()<<"\n";
    uno.setdia(9);
    cout<<"dia de fabricaion::\n";
    cout<<uno.getdia()<<"\n";
    uno.setsalidas(24);
    cout<<"salida de embarque::\n";
    cout<<uno.getsalidas()<<"\n";
    uno.setserie(1234112);
    cout<<"nuemro de serie de avion::\n";
    cout<<uno.getserie()<<"\n";
    return 0;
}
