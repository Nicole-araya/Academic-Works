class Administrador {
    dom;
    modalPolizas;

    state;  // state variables: entities, entity, mode (Add|Edit)

    constructor() {
        this.state = {'entities': new Array(), 'entity': this.emptyEntity(), 'mode': ''};
        this.dom = this.render();
        this.modalPolizas = new bootstrap.Modal(this.dom.querySelector('#modalPoliza'));
        this.modalCreate = new bootstrap.Modal(this.dom.querySelector('#modalCreate'));

    }

    render = () => {
        const html = `
          
            ${this.renderList()}  
            ${this.renderModalPoliza()}
            ${this.renderModalCreate()}
        `;
        var rootContent = document.createElement('div');
        rootContent.id = 'administrador';
        rootContent.innerHTML = html;
        return rootContent;
    }

    //MODAL CREATE

    renderModalCreate = () => {
        return `
          <div id="modalCreate" class="modal fade" tabindex="-1">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header" >
                        <h4 class="card-title mt-3 text-center">Agregar</h4>
                       <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>
                    <form id="formCreate" >
                    <div id="createbody" class="modal-body">
                         
     
                    </div>
                    <div class="modal-footer">
                        <button id="apply" type="button" class="btn btn-primary" >Agregar</button>
                    </div>
                    </form>                 
                </div>         
            </div>          
        </div>   
     `;
    }

    //MODAL POLIZA

    renderModalPoliza = () => {
        return `
         <div id="modalPoliza" class="modal fade" tabindex="-1">
            <div class="modal-dialog modal-xl">
                <div class="modal-content">
                    <div class="modal-header" >  
                        <p class="h2">Polizas</p>
                       <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>

                        <table class="table table-dark table-hover">
                            <thead >
                                <th scope="col">Numero Placa:</th>
                                <th scope="col">Marca:</th>
                                <th scope="col">Modelo:</th>
                                <th scope="col">Anio:</th>
                                <th scope="col">Valor:</th>
                                <th scope="col">Plazo de Pago:</th>
                                <th scope="col">Fecha de vigencia:</th>
                                <th scope="col">Categoria:</th>
                                <th scope="col">Cobertura:</th>
                                <th scope="col">Costo:</th>
                            </thead>
                            <tbody id="tablebody">
        
                            </tbody>
                        </table>

                </div>         
            </div>          
        </div>  
     `;
    }

    renderList = () => {
        return `
        <div id="list" class="container-xxl p-3">     
            <div id="tablename" class="card bg-dark" style=" overflow: auto">
                
                <div class="card-body mx-auto w-75">
        
                    <form id="form">
                        <div class="input-group mb-3">
                            <span class="input-group-text">Buscador</span>
                            <input id="name" type="text" class="form-control">
                          <div id="botones" class="btn-toolbar">
                            
                            
                          </div>  
                        </div>
                    </form>
        
                    <div class="table-responsive " style="max-height: 700px; overflow: auto">
                        <table class="table table-dark table-hover">
                            <thead id="listThead">
                            </thead>
                            <tbody id="listbody">
                            </tbody>
                        </table>
                    </div>                 
                </div>
            </div>
        </div>
        `;
    }

    renderBotones = () => {
        let html = '';

        if (this.state.mode === '1') { //clientes
            html += `
              <div class="btn-group me-2"><button type="button" class="btn btn-secondary" id="searchClientes">Buscar</button> </div>`;

        }
        if (this.state.mode === '2') { //categorias-coberturas
            html += `
              <div class="btn-group me-2"><button type="button" class="btn btn-secondary" id="searchCategorias">Buscar</button> </div>
              <div class="btn-group me-2"><button type="button" class="btn btn-primary" id="createCate">Agregar Categoria</button> </div>
              <div class="btn-group me-2"><button type="button" class="btn btn-primary" id="createCober">Agregar Cobertura</button> </div>  
                `;

        }
        if (this.state.mode === '3') { //marcas-modelos
            html += `
            <div class="btn-group me-2"><button type="button" class="btn btn-secondary" id="searchMarcas">Buscar</button> </div>
            <div class="btn-group me-2"><button type="button" class="btn btn-primary" id="createMar">Create Marca</button> </div>
            <div class="btn-group me-2"><button type="button" class="btn btn-primary" id="createMod">Create Modelo</button> </div>
                `;

        }

        this.dom.querySelector('#administrador>#list #form #botones').replaceChildren();
        this.dom.querySelector('#administrador>#list #form #botones').innerHTML = html;

        this.dom.querySelector('#administrador>#list #form #botones #searchClientes')?.addEventListener('click', e => this.searchClientes());
        this.dom.querySelector('#administrador>#list #form #botones #searchCategorias')?.addEventListener('click', e => this.searchCategoria());
        this.dom.querySelector('#administrador>#list #form #botones #searchMarcas')?.addEventListener('click', e => this.searchMarca());

        this.dom.querySelector('#administrador>#list #form #botones #createCate')?.addEventListener('click', e => this.makenewCategoria());
        this.dom.querySelector('#administrador>#list #form #botones #createCober')?.addEventListener('click', e => this.makenewCobertura());

        this.dom.querySelector('#administrador>#list #form #botones #createMar')?.addEventListener('click', e => this.makenewMarca());
        this.dom.querySelector('#administrador>#list #form #botones #createMod')?.addEventListener('click', e => this.makenewModelo());

    }

    showModal = async () => {

        this.modalCreate.show();
    }

    //MODALS CREATE

    makenewCategoria = () => {
        let html = `
       <div class="input-group mb-3">
         <span class="input-group-text">Categoria</span>
         <input type="text" class="form-control" id="categoria" name="categoria">
       </div>
     `;

        const createBody = this.dom.querySelector("#modalCreate #formCreate #createbody");
        createBody.innerHTML = html;

        this.showModal();

        this.dom.querySelector('#modalCreate #formCreate #apply').addEventListener('click', this.addCate);
    }
    
    makenewMarca = () => {
        let html = `
       <div class="input-group mb-3">
         <span class="input-group-text">Marca</span>
         <input type="text" class="form-control" id="Marca" name="Marca">
       </div>
     `;

        const createBody = this.dom.querySelector("#modalCreate #formCreate #createbody");
        createBody.innerHTML = html;

        this.showModal();

        this.dom.querySelector('#modalCreate #formCreate #apply').addEventListener('click', this.addMarca);
    }

    makenewCobertura = async () => {
        let html = `
       <div class="input-group mb-3">
         <span class="input-group-text">Cobertura</span>
         <input type="text" class="form-control" id="cobertura" name="cobertura">
       </div>
        <div class="input-group mb-3">
         <span class="input-group-text">Costo Minimo</span>
         <input type="text" class="form-control" id="costoMinimo" name="costoMinimo">
       </div>
       <div class="input-group mb-3">
         <span class="input-group-text">Porcentaje</span>
         <input type="text" class="form-control" id="porcentaje" name="porcentaje">
       </div>
        <span class="input-group-text">Categorias</span>
     `;

        const createBody = this.dom.querySelector("#modalCreate #formCreate #createbody");
        createBody.innerHTML = html;

        const request = new Request(`${backend}/administrador/onlyCategorias`, {method: 'GET', headers: {}});

        try {
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }

            const categoriasData = await response.json();

            categoriasData.forEach((categoria) => {
                const radio = document.createElement("input");
                radio.type = "radio";
                radio.name = "categoria";
                radio.value = categoria.detalle;
                radio.setAttribute("codigoCategoria", categoria.cod);

                const label = document.createElement("label");
                label.textContent = categoria.detalle;

                const div = document.createElement("div");
                div.appendChild(radio);
                div.appendChild(label);

                const contenedor = this.dom.querySelector("#modalCreate #formCreate #createbody");
                contenedor.appendChild(div);
            });

            // Mostrar el modal
            this.showModal();

        } catch (error) {
            console.error(error);
        }

        this.dom.querySelector('#modalCreate #formCreate #apply').addEventListener('click', this.addCober);
    }

    makenewModelo = async () => {
        let html = `
       <div class="input-group mb-3">
         <span class="input-group-text">Modelo</span>
         <input type="text" class="form-control" id="modelo" name="modelo">
        </div>
        <div id="radio"> <span style='margin-left:4em;font-weight: bold;'>Marcas</span> </div>
        <div class="custom-file">
              <br>
              <input type="file" class="custom-file-input" id="customFile" accept="image/jpeg, image/png, image/jpg">
              <label class="custom-file-label" for="customFile">Choose file</label>
        </div>
     `;

        this.dom.querySelector("#modalCreate #formCreate #createbody").innerHTML = html;

        const request = new Request(`${backend}/administrador/onlyMarcas`, {method: 'GET', headers: {}});

        try {
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }

            const marcasData = await response.json();

            marcasData.forEach((marca) => {
                const radio = document.createElement("input");
                radio.type = "radio";
                radio.name = "marca";
                radio.value = marca.marca;
                radio.setAttribute("codigoMarca", marca.cod);

                const label = document.createElement("label");
                label.textContent = marca.marca;

                const div = document.createElement("div");
                div.appendChild(radio);
                div.appendChild(label);

                const contenedor = this.dom.querySelector("#modalCreate #formCreate #createbody #radio");
                contenedor.appendChild(div);
            });
                
               
            // Mostrar el modal
            this.showModal();

        } catch (error) {
            console.error(error);
        }

        this.dom.querySelector('#modalCreate #formCreate #apply').addEventListener('click', this.addModelo);
    }
    
    //EVENTOS DE AGRAGAR

    addCate = async () => {

        const detalle = document.querySelector('#modalCreate #formCreate #createbody #categoria').value;
        
        if (detalle === '') {
        alert('Por favor, rellena el campo');
        return;
    }
        const request = new Request(`${backend}/administrador/newCategoria?detalle=${detalle}`, {method: 'POST', headers: {}});

        try {
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }

            // Recargar lista
            this.listCategorias();
             this.modalCreate.hide();
        } catch (error) {
            console.error(error);
        }
    }
    
    addCober = async () => {
      const detalle = document.querySelector('#modalCreate #formCreate #createbody #cobertura').value;
      const costoMinimo = document.querySelector('#modalCreate #formCreate #createbody #costoMinimo').value;
      const porcentaje = document.querySelector('#modalCreate #formCreate #createbody #porcentaje').value;
      const categoriaInput = document.querySelector('#modalCreate #formCreate #createbody input[name="categoria"]:checked');
      
            if (detalle === '' || costoMinimo === '' || porcentaje === '' || !categoriaInput ) {
                    alert('Por favor, complentar todos los datos');
                    return;
                }

       const categoria = categoriaInput.getAttribute("codigoCategoria");
       
      const request = new Request(`${backend}/administrador/newCobertura?detalle=${detalle}&costoMinimo=${costoMinimo}&porcentaje=${porcentaje}&categoria=${categoria}`, { method: 'POST', headers: {} });

      try {
        const response = await fetch(request);
        if (!response.ok) {
          errorMessage(response.status);
          return;
        }

        // Recargar lista
        this.listCategorias();
        this.modalCreate.hide();
      } catch (error) {
        console.error(error);
      }
  }

    addMarca = async () => {
        const marca = document.querySelector('#modalCreate #formCreate #createbody #Marca').value;
        
        if (marca === '') {
        alert('Por favor, rellena el campo');
        return;
    }
        const request = new Request(`${backend}/administrador/newMarca?marca=${marca}`, {method: 'POST', headers: {}});

        try {
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);

                return;
            }

            // Recargar lista
            this.listMarcas();
            this.modalCreate.hide();
        } catch (error) {
            console.error(error);
        }
    }

    addModelo = async () => {
      const modelo = document.querySelector('#modalCreate #formCreate #createbody #modelo').value;
      const marcaInput = document.querySelector('#modalCreate #formCreate #createbody input[name="marca"]:checked');

                if (modelo === '' || !marcaInput ) {
                    alert('Por favor, complentar todos los datos');
                    return;
                }
                
      const marca= marcaInput.getAttribute("codigomarca");

      try {
           const imagenAdded = await this.addImagen();

            if (!imagenAdded) {
              // Si la imagen no se agregó, no se continúa con la creación del modelo
              alert('Error al cargar la imagen. Por favor, intenta nuevamente.');
              return;
            }
          
        const request = new Request(`${backend}/administrador/newModelo?modelo=${modelo}&marcaCod=${marca}`, { method: 'POST', headers: {} });
        const response = await fetch(request);
        if (!response.ok) {errorMessage(response.status);return;}
        
        await this.addImagen();

        // Recargar lista
        this.listMarcas();
        
      } catch (error) {
        console.error(error);
      }
     
  }


    addImagen = async()=>{
  const nombreMo = document.querySelector('#modalCreate #formCreate #createbody #modelo').value;
  const imagen = document.querySelector("#modalCreate #formCreate #createbody #customFile").files[0];
  
  if (!imagen) {
    return false;
  }
  
  var data = new FormData();
  data.append("imagen", imagen);

  const request = new Request(`${backend}/administrador/${nombreMo}/imagen`, { method: 'POST', body: data });

  try {
    const response = await fetch(request);
    if (!response.ok) {
      errorMessage(response.status);
      return;
    }

    // Recargar lista
    this.listMarcas();
    this.modalCreate.hide();
     return true;
  } catch (error) {
    console.error(error);
    return false;
  }
        
    }
    //LISTAS

    listClientes = () => {

        const request = new Request(`${backend}/administrador/clientes`, {method: 'GET', headers: {}});
        (async () => {


            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }
            
            var clientes = await response.json();
            this.state.entities = clientes;
            this.state.mode = '1';
            
            this.dom.querySelector('#administrador #list #tablename #listThead').replaceChildren();
            var listing = this.dom.querySelector("#administrador #list #tablename #listThead");
            listing.innerHTML = "";
            this.colClientes(listing);


            var listing2 = this.dom.querySelector("#administrador #list #tablename #listbody");
            listing2.innerHTML = "";
            this.state.entities.forEach(e => this.rowClientes(listing2, e));

            this.renderBotones();
        })();
    }

    rowClientes = (list, c) => {

        var tr = document.createElement("tr");
        tr.innerHTML = `
                <td>${c.nombre}</td>     
                <td>${c.user.cedula}</td>
                <td>${c.telefono} </td>
                <td>${c.correo}</td>
                <td>${c.medioPago}</td>
                <td><a id="polizas" class="btn btn-primary" href="#" role="button">Ver</a></td>`;
        list.append(tr);

        var verButton = tr.querySelector("#polizas");
        verButton.polizas = c.polizas;
        verButton.addEventListener("click", this.verPoliza);
    }

    colClientes = (list) => {
        var tr = document.createElement("tr");
        tr.innerHTML = `
                <th scope="col">Nombre</th>
                <th scope="col">Cedula</th>
                <th scope="col">Telefono</th>
                <th scope="col">Correo</th>
                <th scope="col">Medio de pago</th>
                <th scope="col">Polizas</th>`;
        list.append(tr);
    }

    listCategorias = () => {
        const request = new Request(`${backend}/administrador/categorias`, {method: 'GET', headers: {}});
        (async () => {
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }
            var clientes = await response.json();
            this.state.entities = clientes;
            this.state.mode = '2';

            this.dom.querySelector('#administrador #list #tablename #listThead').replaceChildren();
            var listing = this.dom.querySelector("#administrador #list #tablename #listThead");
            listing.innerHTML = "";
            this.colCategorias(listing);


            var listing2 = this.dom.querySelector("#administrador #list #tablename #listbody");
            listing2.innerHTML = "";
            this.state.entities.forEach(e => this.rowCategorias(listing2, e));

            this.renderBotones();
        })();
    }

    rowCategorias = (list, c) => {
        var tr = document.createElement("tr");
        tr.innerHTML = `
                <td>${c.cod}</td>
                <td>${c.detalle}</td>
                <td>${c.cobertura.map(e => e.detalle).join("<br>")}</td>`;
        list.append(tr);
    }

    colCategorias = (list) => {
        var tr = document.createElement("tr");
        tr.innerHTML = `
                <th scope="col">Codigo</th>
                <th scope="col">Detalle</th>
                <th scope="col">Coberturas</th>`;
        list.append(tr);
    }

    listMarcas = () => {
        const request = new Request(`${backend}/administrador/marcas`, {method: 'GET', headers: {}});
        (async () => {
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }
            var clientes = await response.json();
            this.state.entities = clientes;
            this.state.mode = '3';

            this.dom.querySelector('#administrador #list #tablename #listThead').replaceChildren();
            var listing = this.dom.querySelector("#administrador #list #tablename #listThead");
            listing.innerHTML = "";
            this.colMarcas(listing);


            var listing2 = this.dom.querySelector("#administrador #list #tablename #listbody");
            listing2.innerHTML = "";
            this.state.entities.forEach(e => this.rowMarcas(listing2, e));

            this.renderBotones();
        })();
    }

    rowMarcas = (list, c) => {
        var tr = document.createElement("tr");
        tr.innerHTML = `
                <td>${c.marca}</td>
                 <td>${c.modelos.map(e => `
            <div>
              <p>${e.modelo}</p> 
              <img class="flag" src="${backend}/administrador/${e.modelo}/imagen" style="width: 200px; height: auto;"> 
            </div>`).join("<br>")}</td>`;
        
        list.append(tr);
    }

    colMarcas = (list) => {
        var tr = document.createElement("tr");
        tr.innerHTML = `
                <th scope="col">Marcas</th>
                <th scope="col">Modelos</th>`;
        list.append(tr);
    }

    emptyEntity = () => {
    }    //EMPTY ENTITY

    verPoliza = async (event) => {
        const polizasData = event.target.polizas;
        //const request = new Request(`${backend}/administrador/polizas`, {method: 'POST', headers: {'Content-Type': 'application/json'}, body: JSON.stringify(polizas)});

        try {
//            const response = await fetch(request);
//            if (!response.ok) {
//                errorMessage(response.status);
//                return;
//            }
//
//            const polizasData = await response.json();

            // Rellenar las filas de la tabla en el modal
            const tableBody = this.dom.querySelector("#tablebody");
            tableBody.innerHTML = "";
            polizasData.forEach((poliza) => {
                let plazo;
                if(poliza.plazopago === 1){plazo="Trimestral";}
                if(poliza.plazopago === 2){plazo="Semestral";}
                if(poliza.plazopago === 3){plazo="Anual";}
                const tr = document.createElement("tr");
                tr.innerHTML = `
        <td>${poliza.numPlaca}</td>
        <td>${poliza.modelo.marca.marca}</td>
        <td>${poliza.modelo.modelo}</td>
        <td>${poliza.anio}</td>
        <td>${poliza.valor}</td>
        <td>${plazo}</td>
        <td>${poliza.fechavigencia}</td>
                
        <td>${poliza.coberturas.map(e => e.categoria.detalle).join("<br>")}</td>
        <td>${poliza.coberturas.map(e => e.detalle).join("<br>")}</td>       
       
        <td>${poliza.costo}</td>
      `;
                tableBody.appendChild(tr);
            });

            // Mostrar el modal
            this.modalPolizas.show();
        } catch (error) {
            console.error(error);
        }
    }

    //BUSQUEDAS

    searchClientes = () => {
        var busqueda = document.getElementById('name').value;
        const request = new Request(`${backend}/administrador/searchCliente?name=${busqueda}`, {method: 'GET', headers: {}});
        (async () => {
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }
            var clientes = await response.json();
            this.state.entities = clientes;
            this.state.mode = '1';

            var listing2 = this.dom.querySelector("#administrador #list #tablename #listbody");
            listing2.innerHTML = "";
            this.state.entities.forEach(e => this.rowClientes(listing2, e));
        })();
    }

    searchCategoria = () => {
        var busqueda = document.getElementById('name').value;
        const request = new Request(`${backend}/administrador/searchCategoria?name=${busqueda}`, {method: 'GET', headers: {}});
        (async () => {
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }
            var categoria = await response.json();
            this.state.entities = categoria;
            this.state.mode = '2';

            var listing2 = this.dom.querySelector("#administrador #list #tablename #listbody");
            listing2.innerHTML = "";
            this.state.entities.forEach(e => this.rowCategorias(listing2, e));
        })();
    }

    searchMarca = () => {
        var busqueda = document.getElementById('name').value;
        const request = new Request(`${backend}/administrador/searchMarca?name=${busqueda}`, {method: 'GET', headers: {}});
        (async () => {
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }
            var marcas = await response.json();
            this.state.entities = marcas;
            this.state.mode = '3';

            var listing2 = this.dom.querySelector("#administrador #list #tablename #listbody");
            listing2.innerHTML = "";
            this.state.entities.forEach(e => this.rowMarcas(listing2, e));
        })();
    }

}
