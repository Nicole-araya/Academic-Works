class App{
  dom;
  modal; // login modal
  modalRegister; // login modal
  
  state;  // state variables: if any
  
  administrador;
  cliente;

  constructor(){ // aqui se llaman todos los metodos de la app
    this.state = {};
    this.dom = this.render(); 
    this.modal = new bootstrap.Modal(this.dom.querySelector('#app>#modal'));
    this.modalRegister = new bootstrap.Modal(this.dom.querySelector('#app>#modalRegister'));
    
    this.dom.querySelector('#app>#modal #applyLogin').addEventListener('click', (event) => {
        event.preventDefault();
        if (this.dom.querySelector('#app>#modal #formLogin').checkValidity()) {
          this.login();
        } else {
          alert('Debe llenar todos los campos');
        }
    });
    
    this.dom.querySelector('#app>#modal #register').addEventListener('click', e=>this.showModalRegister());
    
    this.dom.querySelector('#app>#modalRegister #applyRegister').addEventListener('click', (event) => {
        event.preventDefault();
        if (this.dom.querySelector('#app>#modalRegister #formRegister').checkValidity()) {
          this.register();
        } else {
          alert('Debe llenar todos los campos');
        }
    });
    
    //this.dom.querySelector('#app>#modalRegister #applyRegister').addEventListener('click', e=>this.register());
    
    this.renderBodyFiller();
    this.renderMenuItems(); // aqui se llama la metodo de los tabs
    
    this.administrador = new Administrador();
    this.cliente = new Cliente();
    
  }
  

  render=()=>{ // retorna html
    const html= `
            ${this.renderMenu()}
            ${this.renderBody()} 
            ${this.renderFooter()}
            ${this.renderModal()}
            ${this.renderModalRegister()}
        `;
       let rootContent= document.createElement('div');
       rootContent.id='app';
       rootContent.innerHTML=html;
       return rootContent;
  }
  
    renderMenu=()=>{
    return `
    <header id="header" class="p-3 bg-dark text-white">
    <div class="container">
      

      <div class="d-flex flex-wrap align-items-center justify-content-center justify-content-lg-start">
        <a href="/" class="d-flex align-items-center mb-2 mb-lg-0 text-white text-decoration-none">
          <svg class="bi me-2" width="40" height="32" role="img" aria-label="Bootstrap"><use xlink:href="#bootstrap"></use></svg>
        </a>
        <i class="fa-solid fa-car-burst fa-2xl"></i>
        <a href="#" class="nav-link px-2 text-secondary">Seguros Infinitos</a>
        
        <ul id=menuheader class="nav col-12 col-lg-auto me-lg-auto mb-2 justify-content-center mb-md-0">

        </ul>

        <div class="text-end">
        
         <ul id='menuItems' style="list-style-type: none;"> 
           
         </ul>
        
        </div>
      </div>
    </div>
  </header>
        `;
  }

    renderBody=()=>{
     return `
         <div id="body">   
         </div>          
     `;
    }

    renderFooter=()=>{
     return `
         <footer id="footer" class="bg-dark text-white mt-4 w-100 fixed-bottom">
             <div class="container-fluid py-2">

                 <div class="row">
                     <div class="col-md-2"><h5>Seguros Infinitos </h5></div>
                     <div class="col-md-7"><h4>
                         <i class="fab fa-twitter"></i>
                         <i class="fab fa-facebook"></i>
                         <i class="fab fa-instagram"></i></h4>
                     </div>
                     <div class="col-md-3 text-right small align-self-end">©2023 Tsf, Inc.</div>
                 </div>
             </div>
         </footer> 
     `;
    }    

    renderModal = () => {
        // Pop up para login
        return `
          <div id="modal" class="modal fade" tabindex="-1">
            <div class="modal-dialog">
              <div class="modal-content">
                <div class="modal-header">
                  <img class="img-circle" id="img_logo" src="images/user.png" style="max-width: 50px; max-height: 50px" alt="logo">
                  <span style='margin-left:4em;font-weight: bold;'>Login</span>
                  <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>

                <form id="formLogin" class="was-validated">
                    <div class="modal-body">

                        <div class="input-group mb-3">
                          <span class="input-group-text">Identificacion</span>
                          <input type="text" class="form-control" id="logId" name="cedula" required>
                        </div>

                        <div class="input-group mb-3">
                          <span class="input-group-text">Clave</span>
                          <input type="password" class="form-control" id="logClave" name="clave" required>
                        </div>

                        </div>
                        <div class="modal-footer">
                          <button id="applyLogin" type="button" class="btn btn-primary">Login</button>
                        </div>

                    <div class="input-group">
                      <span style="font-style: italic; margin-left: 2em;">No tiene cuenta? ... </span>
                      <a id="register" class="btn btn-info btn-block" style="margin-bottom: 15px; background-color: white; color:red; border:1px solid red" href="#">Registrese aquí</a>
                    </div>

                </form>
              </div>
            </div>
          </div>
        `;
    };


    renderModalRegister=()=>{
           return `
               <div id="modalRegister" class="modal fade" tabindex="-1">
                  <div class="modal-dialog">
                      <div class="modal-content">
                          <div class="modal-header" >
                              <img class="img-circle" id="img_logo" src="images/user.png" style="max-width: 50px; max-height: 50px" alt="logo">
                              <span style='margin-left:4em;font-weight: bold;'>Register</span> 
                             <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                          </div>

                          <form class="was-validated" id="formRegister">
                               <div class="modal-body">
        
                                    <div class="input-group mb-3">
                                        <span class="input-group-text">Nombre</span>
                                        <input type="text" class="form-control" id="regnombre" name="nombre" required>
                                    </div>

                                    <div class="input-group mb-3">
                                        <span class="input-group-text">Cedula</span>
                                        <input type="text" class="form-control" id="regcedula" name="cedula" required>
                                    </div>

                                    <div class="input-group mb-3">
                                        <span class="input-group-text">Clave</span>
                                        <input type="password" class="form-control" id="regClave" name="clave" required>
                                    </div>

                                    <div class="input-group mb-3">
                                        <span class="input-group-text">Numero de telefono</span>
                                        <input type="text" class="form-control" id="regTelefono" name="telefono" required>
                                    </div>

                                    <div class="input-group mb-3">
                                        <span class="input-group-text">Correo</span>
                                        <input type="text" class="form-control" id="regCorreo" name="correo" required>
                                    </div>

                                    <div class="input-group mb-3">
                                        <span class="input-group-text">Medio de pago</span>
                                        <input type="text" class="form-control" id="regMedioPago" name="medioPago" required>
                                    </div>

                                    </div>
                                    <div class="modal-footer">
                                        <button id="applyRegister" type="submit" class="btn btn-primary">Registrarse</button>
                                    </div>

                               </div> 
                          </form>

                      </div>         
                  </div>          
              </div>   
           `;
       }

    renderBodyFiller=()=>{
        let html= `
            <div id='bodyFiller' style='margin-left: 10%; margin-top:100px; width: 80%; text-align: center; font-size: 1.5em'>
                <p>PAGINA PRINCIPAL UWUr</p>
                
            </div>
        `;
        this.dom.querySelector('#app>#body').replaceChildren();
        this.dom.querySelector('#app>#body').innerHTML=html;        
    } 

    renderMenuItems=()=>{ // items de los tabs segun el rol del usuario
        let html='';
        let userhtml='';
        if(globalstate.session===null){
            html+=`
             <li>
                 <button id="login" type="button" class="btn btn-outline-light me-2">Login</button>
              </li>
            `;
        } else{
            if(globalstate.session.rol===1){
                userhtml+=`
                    <li class="nav-item"><a id="listaPolizas" class="nav-link" href="#">Polizas</a></li>
                    <li class="nav-item"><a id="datosCliente" class="nav-link" href="#">Cliente</a></li>
                `;

            }
            if(globalstate.session.rol===2){
                userhtml+=`
                <li  class="nav-item"><a id="clientes" class="nav-link" href="#">Clientes</a></li>
                <li  class="nav-item"><a id="categorias" class="nav-link" href="#">Categorias-Coberuras</a></li>
                <li  class="nav-item"><a id="marcas" class="nav-link" href="#">Marca-Modelos</a></li>
                `;

            }
            html+=`
              <li>
                <button id="logout" type="button" class="btn btn-warning">Logout ${globalstate.session.cedula}</button>  
              </li>
            `;
        };
        
        //PARA LOGIN Y LOGOUT en menuItems! 
        this.dom.querySelector('#app>#header #menuItems').replaceChildren();
        this.dom.querySelector('#app>#header #menuItems').innerHTML=html;
        //this.dom.querySelector('#app>#header #menuheader').replaceChildren();
        this.dom.querySelector('#app>#header #menuheader').innerHTML=userhtml;
        
        this.dom.querySelector("#app>#header #menuItems #login")?.addEventListener('click',e=>this.modal.show());
        this.dom.querySelector("#app>#header #menuItems #logout")?.addEventListener('click',e=>this.logout());
        
        this.dom.querySelector("#app>#header #menuheader #categorias")?.addEventListener('click',e=>this.CategoriasShow());
        this.dom.querySelector("#app>#header #menuheader #clientes")?.addEventListener('click',e=>this.ClientesShow());
        this.dom.querySelector("#app>#header #menuheader #marcas")?.addEventListener('click',e=>this.MarcasShow());
        
        this.dom.querySelector("#app>#header #menuheader #listaPolizas")?.addEventListener('click',e=>this.polizasShow());
        this.dom.querySelector("#app>#header #menuheader #datosCliente")?.addEventListener('click',e=>this.datosClienteShow());
        
        
        if(globalstate.session !== null){
            switch(globalstate.session.rol){  //Cada uno configura su metodo
                case 1:  //cliente   
                    this.clienteShow();
                    break;
                    
                case 2:  //ADMI 
                    this.administradorShow();
                    break;
            }
        }
        
    }
    
    MarcasShow=()=>{
        this.dom.querySelector('#app>#body').replaceChildren(this.administrador.dom);
        this.administrador.listMarcas();

    }
    
    CategoriasShow=()=>{
        this.dom.querySelector('#app>#body').replaceChildren(this.administrador.dom);
        this.administrador.listCategorias();

    }
    
    ClientesShow=()=>{
        this.dom.querySelector('#app>#body').replaceChildren(this.administrador.dom);
        this.administrador.listClientes();
    }
    
    datosClienteShow=()=>{
        this.dom.querySelector('#app>#body').replaceChildren(this.cliente.dom);
        this.cliente.verDatosCliente();
    }
    
    polizasShow=()=>{
        this.dom.querySelector('#app>#body').replaceChildren(this.cliente.dom);
        this.cliente.listPolizas();
    }
    
    // show dom
    
    administradorShow=()=>{
        this.dom.querySelector('#app>#body').replaceChildren(this.administrador.dom);
        this.administrador.listClientes();
    }
    
    clienteShow=()=>{
        this.dom.querySelector('#app>#body').replaceChildren(this.cliente.dom);
        this.cliente.listPolizas();
    }
    
    
    login=async()=>{
        
        let usuario = Object.fromEntries((new FormData(this.dom.querySelector("#formLogin"))).entries());
        
        ////////////////////////////////////////////////////////
        // request del usuario con los datos del form
       
        let request = new Request(backend+'/session/login', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(usuario)
        });
        
        let response = await fetch(request);
        if (!response.ok) { alert('Usuario o contraseña incorrectos'); return; }
        usuario = await response.json(); // se hizo login y se devuelve el usuario original con su id y rol asignado (clave vacia xq no es seguro)
        
        ////////////////////////////////////////////////////////
        // se actualizan los datos de la sesion
        
        globalstate.session = usuario;
        globalstate.session.rol = usuario.tipo;
        
        ////////////////////////////////////////////////////////
        // se actualiza el contenido del sitio
        
        this.modal.hide();
        this.renderMenuItems();
        this.dom.querySelector('#app>#modal #formLogin').reset();
    }
    
    logout=async()=>{
        globalstate.session = null;
        
        const request = new Request(backend+'/session/login', {
            method: 'DELETE', 
            headers: {}
        });
        
        this.dom.querySelector('#app>#body').replaceChildren();
        this.renderBodyFiller();
        this.renderMenuItems();
    }
    
    showModalRegister=async()=>{
        this.modalRegister.show();
        this.modal.hide();
    }
    
    register=async()=>{
        
        const registerData = Object.fromEntries((new FormData(this.dom.querySelector("#formRegister"))).entries());
        
        let urlParams = new URL(backend+'/session/register');
        urlParams.searchParams.append('nombre', registerData.nombre);
        urlParams.searchParams.append('cedula', registerData.cedula);
        urlParams.searchParams.append('clave', registerData.clave);
        urlParams.searchParams.append('telefono', registerData.telefono);
        urlParams.searchParams.append('correo', registerData.correo);
        urlParams.searchParams.append('medioPago', registerData.medioPago);
        
        const request = new Request(urlParams, {
            method: 'POST',
            headers: {}
        });

        const response = await fetch(request);
        if (!response.ok) { alert('Usuario ya existe'); return; }
        const usuario = await response.json();
        
        ////////////////////////////////////////////////////////
        // se actualizan los datos de la sesion
        
        globalstate.session = usuario;
        globalstate.session.rol = usuario.tipo;
        
        ////////////////////////////////////////////////////////
        // se actualiza el contenido del sitio
        
        this.modalRegister.hide();
        this.renderMenuItems();
        this.dom.querySelector('#app>#modalRegister #formRegister').reset();
    }
} 
