#include <iostream>
#include <string>
using namespace std;
//Declaramos en cada clase el uso de priavte,protected y public

class aviones
{
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
};
//Agragamso el uso de virtual para evitar el error de diamante al heradar de otras calses
class avion_a : virtual public  aviones
{
    protected:
        string fabricacion;
    public:
        avion_a(int a, const string &b,const string &c)
               :aviones(a,b),fabricacion(c){}
        string get_fabricacion() const
        {
            return fabricacion;
        }



};
class avion_b : virtual public  aviones
{
    protected:
        int motores;
    public:
        avion_b(int a, const string &b,int c)
                :aviones(a,b),motores(c){}
        int get_motores() const
        {
           return  motores;
        }


};
class monitoreo:  public avion_a ,public avion_b//heredamos todas las caractersticas de nuestras anterores clases que pertenecen a public  y protected
{
    protected:
        string destino;
    public:
    	monitoreo(int a, const string &b,int c, const string &d,int e,const string &f ,const string &g)
               :aviones(a,b),avion_a(e,d,f),avion_b(a,b,c),destino(g){}
        const string &getdestino() {return  destino;}
};

int main()
{
	//Inicializamos nuestra clase que ha heredados de aviones , avion_a y avion_b
	
	monitoreo uno(32,"aleman",34,"x112",45,"PQ-45","HK-78");	
    string a=uno.get_marca();
	cout<<a<<"\n";
    return 0;
}
