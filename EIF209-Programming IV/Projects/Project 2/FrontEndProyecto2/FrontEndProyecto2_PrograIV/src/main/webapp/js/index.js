const backend = "http://localhost:8080/BackEndProyecto2_PrograIV/api";

let globalstate = {session:null};

let app;

function loaded(){
    app = new App(); // aqui se crea la aplicacion
    document.querySelector('#root').replaceChildren(app.dom);
}

document.addEventListener("DOMContentLoaded", loaded);
 
function errorMessage(code){
    alert(`Error. Status: ${code}`);
}