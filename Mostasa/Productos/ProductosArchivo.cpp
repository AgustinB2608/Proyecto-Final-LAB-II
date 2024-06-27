#include "../Productos/ProductosArchivo.h"
#include <iostream>
using namespace std;
#include <string>
#include <cstring>
ProductoArchivo::ProductoArchivo(){
    _Filename = "Productos.dat";
}

ProductoArchivo::ProductoArchivo(string Filename){
     _Filename=Filename;
}


bool ProductoArchivo::abrirA(string modo){
    _p = fopen(_Filename.c_str(), modo.c_str());
    if(_p==nullptr){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return false;
    }
    else{return true;}
}
void ProductoArchivo::cerrarA(){
    fclose(_p);

}

bool ProductoArchivo::guardar(Producto x){
    if(abrirA("ab")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return false;
    }
    bool grabo = fwrite(&x,sizeof(Producto),1,_p);
    cerrarA();
    return grabo;
}

int ProductoArchivo::buscar(int ID){ ///BUSCA PRODUCTO POR ID
    Producto x;
    int pos=0;
     if(abrirA("rb")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return -1;
    }
    while(fread(&x,sizeof(Producto),1,_p)){
        if(x.getID()==ID){
            break;
        }
        pos++;
    }
    cerrarA();
    if(x.getID() == ID){
        return pos;
    }
    else{return -1;}

}
Producto ProductoArchivo::leer(int pos){
    Producto x;
    if(abrirA("rb")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        x.setID(-1);
        return x;
    }
    fseek(_p,sizeof (Producto)*pos,0);
    fread(&x,sizeof(Producto),1,_p);
    cerrarA();
    return x;
}
int ProductoArchivo::getCantidadRegistros(){
    if (abrirA("rb")==false){
            cout<<"No se pudo abrir el archivo correctamente"<<endl;
            return 0;
    }
    fseek(_p,0,2);
    int cantbyte = ftell(_p);
    int cantreg = cantbyte/sizeof(Producto);

    cerrarA();
    return cantreg;

}

bool ProductoArchivo::Modificar(Producto x,int pos){
   bool guardado;
   if (abrirA("rb+")==false){
    cout<<"No se encontró el archivo."<<endl;
    return false;
   }
   fseek(_p,sizeof(Producto)*pos,0);
   guardado = fwrite (&x,sizeof(Producto),1,_p);
   cerrarA();
   return guardado;
 }

bool ProductoArchivo::realizarCopia(string filename){
    FILE *pBak;
    Producto x;

    pBak=fopen(filename.c_str(),"wb");
    if(pBak==nullptr){
        return false;
    }

    int cantreg = getCantidadRegistros();
    for(int i=0;i<cantreg;i++){
        x = leer(i);
        fwrite(&x,sizeof(Producto),1,pBak);
    }
    fclose(pBak);
    return true;
}

bool ProductoArchivo::restaurarCopia(string filename){
    Producto x;
    ProductoArchivo archibak(filename.c_str());

    if(!abrirA("wb")){
        return false;
    }

    int cantreg = archibak.getCantidadRegistros();


    for(int i=0;i<cantreg;i++){
        x = archibak.leer(i);
        fwrite(&x,sizeof(Producto),1,_p);
    }
    cerrarA();
    return true;
}
int ProductoArchivo::CopiarRegVec(Producto *v,int cant){
    int Activo = 0;
    int totalReg = getCantidadRegistros();
    if (cant > totalReg) {
        cant = totalReg; // Asegurarse de no leer más de lo disponible
    }
    for (int i = 0; i < cant; ++i) {
        Producto x = leer(i);
        if(x.getDisponible()){
        v[i] = x;
        Activo++;
        }
    }
    return Activo;
}
