let globalstate = {session:null};

let app;

function loaded(){
    app = new App();
    document.querySelector('#root').replaceChildren(app.dom);
}

document.addEventListener("DOMContentLoaded", loaded);
 
function errorMessage(code){
    alert(`Error. Status: ${code}`);
}