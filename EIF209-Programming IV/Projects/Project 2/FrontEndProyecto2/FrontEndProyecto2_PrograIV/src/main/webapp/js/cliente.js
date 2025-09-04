/* global bootstrap */

class Cliente {
    dom;
    modalDatos;
    modalNuevaPoliza;
    state;

    constructor() {
        
        this.state = {
            'entities': new Array(), 
            'entity': this.emptyEntity(), 
            'mode': ''
        };
        
        this.dom = this.render();
        
        this.modalDatos = new bootstrap.Modal(this.dom.querySelector('#cliente #modalDatos'));
        this.modalNuevaPoliza = new bootstrap.Modal(this.dom.querySelector('#cliente #modalNuevaPoliza'));
        this.dom.querySelector('#cliente #modalNuevaPoliza #modalDatosBasicosContent').innerHTML = this.renderDatosBasicos();
        this.dom.querySelector('#cliente #modalNuevaPoliza #modalCoberturasContent').innerHTML = this.renderCoberturas();
        this.dom.querySelector('#cliente #modalNuevaPoliza #modalPagoContent').innerHTML = this.renderPago();
        
        this.dom.querySelector('#cliente #modalNuevaPoliza #btnDimissCompra').addEventListener('click',e=>this.dimissCompra());
        this.dom.querySelector('#cliente #modalNuevaPoliza #btnFooter').addEventListener('click',e=>this.procederPago(e));
        this.dom.querySelector('#cliente #list #agregarPoliza').addEventListener('click', e=>this.modalNuevaPoliza.show());
        this.dom.querySelector('#cliente #list #searchPoliza').addEventListener('click', e=>this.searchPolizas());
        //this.dom.querySelector('#cliente #modalDatos #clGuardarCambios').addEventListener('click', e => this.modalDatos.hide());
        
        const fechaVigenciaInput = this.dom.querySelector('#cliente #modalNuevaPoliza #modalDatosBasicosContent #formDatosBasicos #fechaVigencia');
        const fechaActual = new Date().toISOString().split('T')[0];
        fechaVigenciaInput.value = fechaActual;
    }
    
    render=()=> {
        
        const html = `
            ${this.renderList()}
            ${this.renderModalDatosPoliza()}
            ${this.renderNuevaPoliza()}
            
        `;
        
        let rootContent = document.createElement('div');
        rootContent.id = 'cliente';
        rootContent.innerHTML = html;
        return rootContent;
    }
    
    updateCliente=async()=>{
        
        const formDatosCliente = this.dom.querySelector('#cliente #modalDatos #formDatos');
        
        let urlParams = new URL(backend+'/cliente/updateCliente');
        
        urlParams.searchParams.append('cedula', globalstate.session.cedula);
        urlParams.searchParams.append('nombre', formDatosCliente.querySelector('#clNombre').value);
        urlParams.searchParams.append('telefono', formDatosCliente.querySelector('#clTelefono').value);
        urlParams.searchParams.append('correo', formDatosCliente.querySelector('#clCorreo').value);
        urlParams.searchParams.append('medioPago', formDatosCliente.querySelector('#clMedioPago').value);
        
        
        const request = new Request(urlParams, {
            method: 'GET',
            headers: {}
        });
        
        try{
            
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }
            
            const datosCliente = await response.json();
            
            document.getElementById('clNombre').value = datosCliente.nombre;
            document.getElementById('clTelefono').value = datosCliente.telefono;
            document.getElementById('clCorreo').value = datosCliente.correo;
            document.getElementById('clMedioPago').value = datosCliente.medioPago;
            
            this.modalDatos.hide();
        } catch (error) {
            console.error(error);
        }
    }
    
    verDatosCliente=async()=>{
        
        let datosCliente = `
        
            <div class="input-group mb-3">
                <span class="input-group-text">Cedula</span>
                <input type="text" class="form-control" id="clCedula" disabled>
            </div>

            <div class="input-group mb-3">
                <span class="input-group-text">Nombre</span>
                <input type="text" class="form-control" id="clNombre" disabled>
            </div>   

            <div class="input-group mb-3">
                <span class="input-group-text">Telefono</span>
                <input type="text" class="form-control" id="clTelefono">
            </div>
        
            <div class="input-group mb-3">
                <span class="input-group-text">Correo</span>
                <input type="text" class="form-control" id="clCorreo">
            </div>
        
            <div class="input-group mb-3">
                <span class="input-group-text">Medio de pago</span>
                <input type="text" class="form-control" id="clMedioPago" >
            </div>

           

        `;
        
        let boton=`<button id="clGuardarCambios" type="button" class="btn btn-primary">Guardar Cambios</button>`;
        this.dom.querySelector('#cliente #modalDatos #formDatos #closeDatos').innerHTML = boton;
        
        this.dom.querySelector('#cliente #modalDatos #formDatos #modalBody').replaceChildren();
        this.dom.querySelector('#cliente #modalDatos #formDatos #modalBody').innerHTML = datosCliente;
        
        this.dom.querySelector('#cliente #modalDatos #clGuardarCambios').addEventListener('click',e=>this.updateCliente());
        
        
        let urlParams = new URL(backend+'/cliente/getClienteById');
        urlParams.searchParams.append('idCliente', globalstate.session.cedula);
        
        const request = new Request(urlParams, {
            method: 'GET',
            headers: {}
        });
        
        try{
            
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }
            
            const datosCliente = await response.json();
            
            document.getElementById('clCedula').value = datosCliente.user.cedula;
            document.getElementById('clNombre').value = datosCliente.nombre;
            document.getElementById('clTelefono').value = datosCliente.telefono;
            document.getElementById('clCorreo').value = datosCliente.correo;
            document.getElementById('clMedioPago').value = datosCliente.medioPago;
            
        } catch (error) {
            console.error(error);
        }
        
        this.modalDatos.show();
        
    }
    
    procederPago=(event)=>{
        event.preventDefault();
            
        const formDatosBasicos = document.getElementById('formDatosBasicos');
        const formCoberturas = document.getElementById('formCoberturas');

        const pagoTab = document.getElementById('modalPago-tab');
        const pagoContent = document.getElementById('modalPagoContent');

        const datosBasicosTab = document.getElementById('modalDatosBasicos-tab');
        const datosBasicosContent = document.getElementById('modalDatosBasicosContent');

        const coberturasTab = document.getElementById('modalCoberturas-tab');
        const coberturasContent = document.getElementById('modalCoberturasContent');
        
        if (formDatosBasicos.checkValidity() && this.validarCheckboxes(formCoberturas)) {

            pagoTab.removeAttribute('disabled');
            pagoTab.setAttribute('aria-selected', 'true');
            pagoContent.classList.add('show', 'active');

            datosBasicosTab.classList.remove('active');
            datosBasicosTab.setAttribute('disabled', 'disabled');
            datosBasicosContent.classList.remove('show', 'active');

            coberturasTab.classList.remove('active');
            coberturasTab.setAttribute('disabled', 'disabled');
            coberturasContent.classList.remove('show', 'active');
            
            const footer = `
                <button type="button" class="btn btn-secondary" id="btnDimissCompra">Cancelar</button>
                <button type="button" class="btn btn-primary" id="btnComprar">Comprar</button>
            `;
            
            document.getElementById('nuevaPolizaFooter').replaceChildren();
            document.getElementById('nuevaPolizaFooter').innerHTML = footer;
            this.dom.querySelector('#cliente #modalNuevaPoliza #btnDimissCompra').addEventListener('click',e=>this.dimissCompra());
            this.dom.querySelector('#cliente #modalNuevaPoliza #btnComprar').addEventListener('click',e=>this.comprar());
            
            this.getCostoPoliza();
            
        } else {
          alert('Debe llenar todos los campos');
        }
        
        
        
    }
    
    validarCheckboxes=(formCoberturas)=>{
        const formData = new FormData(formCoberturas);
        const checkboxes = formCoberturas.querySelectorAll('input[type="checkbox"]');
        let hasSelectedCheckbox = false;

        for (const checkbox of checkboxes) {
            if (checkbox.checked) {
              hasSelectedCheckbox = true;
              break;
            }
        }

        if (!hasSelectedCheckbox) {
          return false;
        }
        
        return true;
    }
    
    dimissCompra=()=>{
        this.modalNuevaPoliza.hide();
        
        document.getElementById('formDatosBasicos').reset();
        document.getElementById('formCoberturas').reset();
        
        const pagoTab = document.getElementById('modalPago-tab');
        const pagoContent = document.getElementById('modalPagoContent');

        const datosBasicosTab = document.getElementById('modalDatosBasicos-tab');
        const datosBasicosContent = document.getElementById('modalDatosBasicosContent');

        const coberturasTab = document.getElementById('modalCoberturas-tab');
        const coberturasContent = document.getElementById('modalCoberturasContent');
        
        pagoTab.setAttribute('disabled', 'disabled');
        pagoTab.setAttribute('aria-selected', 'false');
        datosBasicosTab.classList.remove('active');
        pagoContent.classList.remove('show', 'active');

        datosBasicosTab.classList.add('active');
        datosBasicosTab.removeAttribute('disabled');
        datosBasicosContent.classList.add('show', 'active');

        coberturasTab.classList.remove('active');
        coberturasTab.removeAttribute('disabled');
        coberturasContent.classList.remove('show', 'active');
        
        const footer = `
                <button type="button" class="btn btn-secondary" id="btnDimissCompra">Cancelar</button>
                <button type="button" class="btn btn-primary" id="btnFooter">Confirmar</button>
            `;
            
        document.getElementById('nuevaPolizaFooter').replaceChildren();
        document.getElementById('nuevaPolizaFooter').innerHTML = footer;
        this.dom.querySelector('#cliente #modalNuevaPoliza #btnFooter').addEventListener('click',e=>this.procederPago(e));    
        this.dom.querySelector('#cliente #modalNuevaPoliza #btnDimissCompra').addEventListener('click',e=>this.dimissCompra());
            
        const fechaVigenciaInput = this.dom.querySelector('#cliente #modalNuevaPoliza #modalDatosBasicosContent #formDatosBasicos #fechaVigencia');
        const fechaActual = new Date().toISOString().split('T')[0];
        fechaVigenciaInput.value = fechaActual;
    }
    
    renderNuevaPoliza=()=> {
        return `
          <div id="modalNuevaPoliza" class="modal fade" tabindex="-1">
            <div class="modal-dialog">
              <div class="modal-content">
                <div class="modal-header">
                  <h5 class="modal-title">Nueva Poliza</h5>
                  <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>
                <div class="modal-body">
                  <ul class="nav nav-tabs" id="modalTabs" role="tablist">
                    <li class="nav-item" role="presentation">
                      <button class="nav-link active" id="modalDatosBasicos-tab" data-bs-toggle="tab" data-bs-target="#modalDatosBasicosContent" type="button" role="tab" aria-controls="modalDatosBasicosContent" aria-selected="true">Datos Basicos</button>
                    </li>
                    <li class="nav-item" role="presentation">
                      <button class="nav-link" id="modalCoberturas-tab" data-bs-toggle="tab" data-bs-target="#modalCoberturasContent" type="button" role="tab" aria-controls="modalCoberturasContent" aria-selected="false">Coberturas</button>
                    </li>
                    <li class="nav-item" role="presentation">
                      <button class="nav-link" id="modalPago-tab" data-bs-toggle="tab" data-bs-target="#modalPagoContent" type="button" role="tab" aria-controls="modalPagoContent" aria-selected="false" disabled>Pago y Compra</button>
                    </li>
                  </ul>
                  <div class="tab-content mt-2" id="modalTabsContent">
        
                        <div class="tab-pane fade show active" id="modalDatosBasicosContent" role="tabpanel" aria-labelledby="modalDatosBasicos-tab">
                        </div>
        
                        <div class="tab-pane fade" id="modalCoberturasContent" role="tabpanel" aria-labelledby="modalCoberturas-tab">
                        </div>
        
                        <div class="tab-pane fade" id="modalPagoContent" role="tabpanel" aria-labelledby="modalPago-tab">
                        </div>
        
                  </div>
                </div>
                <div class="modal-footer" id="nuevaPolizaFooter">
                  <button type="button" class="btn btn-secondary" id="btnDimissCompra">Cancelar</button>
                  <button type="button" class="btn btn-primary" id="btnFooter">Confirmar</button>
                </div>
              </div>
            </div>
          </div>
        `;
    }
    
    renderDatosBasicos=()=>{
        this.getMarcas();
        
        return `
            <div id="datosBasicos">

                <form id="formDatosBasicos" class="was-validated">
                    <div>

                        <div class="input-group mb-3">
                          <span class="input-group-text">Numero de placa</span>
                          <input type="text" class="form-control" id="numPlaca" name="numPlaca" required>
                        </div>

                        <div class="input-group mb-3">
                          <span class="input-group-text">Fecha de vigencia</span>
                          <input type="date" class="form-control" id="fechaVigencia" name="fechaVigencia" readonly>
                        </div>

                        <div class="input-group mb-3 d-flex">
                            <span class="input-group-text">Marca-Modelo</span>
                            <div class="flex-grow-1">
                                <select id="comboModelos" class="selectpicker form-select w-100" data-live-search="true" data-style="btn-primary">   
                                    
                                </select>
                            </div>
                        </div>
        
                        <div class="input-group mb-3">
                          <span class="input-group-text">Año</span>
                          <input type="month" class="form-control" id="anio" name="anio" required>
                        </div>

                        <div class="input-group mb-3">
                          <span class="input-group-text">Valor</span>
                          <input type="number" class="form-control" id="valor" name="valor" required>
                        </div>

                        <div class="input-group mb-3">
                            <span class="input-group-text">Método de pago</span>
                                <div class="form-control">
                                    <div class="form-check form-check-inline">
                                        <input class="form-check-input" type="radio" name="metodoPago" id="radio1" value="1" required>
                                        <label class="form-check-label" for="radio1">Trimestral</label>
                                    </div>
                                    <div class="form-check form-check-inline">
                                        <input class="form-check-input" type="radio" name="metodoPago" id="radio2" value="2" required>
                                        <label class="form-check-label" for="radio2">Semestral</label>
                                    </div>
                                    <div class="form-check form-check-inline">
                                        <input class="form-check-input" type="radio" name="metodoPago" id="radio3" value="3" required>
                                        <label class="form-check-label" for="radio3">Anual</label>
                                </div>
                            </div>
                        </div>

                    </div>
                </form>

            </div>
        `;
    }
    
    renderCoberturas=()=>{
        this.getCategorias();
        
        return `
            <div>
                <form id="formCoberturas">

                </form>
            </div>
        `;
    }
    
    renderPago=()=>{
        return `
            <div>
                <form id="formPago" class="was-validated">
        
                </form>
            </div>
        `;
    }
   
    renderList=() => {
        return `
        <div id="list" class="container p-3">     
            <div id="tablename" class="card bg-dark" style="max-widht: 300px; overflow: auto">
                
                <h4 class="card-title text-light mt-3 text-center">zazas</h4>
                <div class="card-body mx-auto w-75">
        
                    <form id="form">
                        <div class="input-group mb-3">
                            <span class="input-group-text">Buscador</span>
                            <input id="name" type="text" class="form-control">
                            <div class="btn-group me-2">
                                <button type="button" class="btn btn-secondary" id="searchPoliza">Buscar</button> 
                            </div>
                            <div class="btn-group me-2">
                            <button id="agregarPoliza" type="button" class="btn btn-primary">Comprar Poliza</button>
                            </div>
 
                        </div>
                    </form>
        
                    <div class="table-responsive " style="max-height: 700px; overflow: auto">
                        <table class="table table-dark table-hover">
                            <thead id="listThead"></thead>
                            <tbody id="listbody"></tbody>
                        </table>
                    </div>
        
                </div>
            </div>
        </div>
        `;
    }
    
    renderModalDatosPoliza=()=>{
     return `
         <div id="modalDatos" class="modal fade" tabindex="-1">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header" >
                        <img class="img-circle" id="img_logo" src="images/car_icon.jpg" style="max-width: 50px; max-height: 50px" alt="logo">
                        <span style='margin-left:4em;font-weight: bold;'>Datos</span> 
                       <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>

                    <form id="formDatos">
        
                        <div class="modal-body" id="modalBody">
        
                            
        
                        </div>
        
                        <div id="closeDatos" class="modal-footer">
                           
                        </div>
        
                    </form>                
                </div>         
            </div>          
        </div>   
     `;
    }
    
    //////////////////////////////////////
    
    listPolizas=()=> {
        let urlParams = new URL(backend+'/cliente/getPolizasByClienteId');
        urlParams.searchParams.append('id', globalstate.session.cedula);

        const request = new Request(urlParams, {
            method: 'GET',
            headers: {}
        });
        
        (async()=> {
            let response = await fetch(request);
            if (!response.ok) { 
                alert('Error al cargar polizas'); 
                return; 
            }
            
            const polizas = await response.json();
            this.state.entities = polizas;
            this.state.mode = '1';
            
            this.dom.querySelector('#cliente #list #tablename #listThead').replaceChildren();
            
            let columns = this.dom.querySelector("#cliente #list #tablename #listThead");
            columns.innerHTML = "";
            this.columnsPolizas(columns);
            
            let rows = this.dom.querySelector("#cliente #list #tablename #listbody");
            rows.innerHTML = "";
            this.state.entities.forEach(e=>this.rowsPolizas(rows, e));
            
        })();
    }
    
    searchPolizas=()=> {
        
        let urlParams = new URL(backend+'/cliente/searchPolizaByPlaca');
        urlParams.searchParams.append('idCliente', globalstate.session.cedula);
        urlParams.searchParams.append('placa', this.dom.querySelector('#cliente #name').value);

        const request = new Request(urlParams, {
            method: 'GET',
            headers: {}
        });
        
        (async()=> {
            let response = await fetch(request);
            if (!response.ok) { 
                alert('Error al cargar polizas'); 
                return; 
            }
            
            const polizas = await response.json();
            this.state.entities = polizas;
            this.state.mode = '1';
            
            this.dom.querySelector('#cliente #list #tablename #listThead').replaceChildren();
            
            let columns = this.dom.querySelector("#cliente #list #tablename #listThead");
            columns.innerHTML = "";
            this.columnsPolizas(columns);
            
            let rows = this.dom.querySelector("#cliente #list #tablename #listbody");
            rows.innerHTML = "";
            this.state.entities.forEach(e=>this.rowsPolizas(rows, e));
            
        })();
    }

    columnsPolizas=(columns)=> {
        const tr = document.createElement("tr");
        
        tr.innerHTML = `
            <th scope="col">Numero</th>
            <th scope="col">Placa</th>
            <th scope="col">Fecha</th>
            <th scope="col">Marca</th>
            <th scope="col">Modelo</th>
            <th scope="col">Valor</th>
            <th scope="col">     </th>
        `;
        
        columns.append(tr);
    }
    
    rowsPolizas=(rows, poliza)=> {

        const tr = document.createElement("tr");
        
        tr.innerHTML = `
                <td>${poliza.cod}</td>
                <td>${poliza.numPlaca}</td>
                <td>${poliza.fechavigencia}</td>
                <td>${poliza.modelo.marca.marca}</td>
                <td>${poliza.modelo.modelo}</td>
                <td>${poliza.valor}</td>
                <td><a id="polizaVer" class="btn btn-primary" href="#" role="button">Ver</a></td>
        `;
        
        let polizaVer = tr.querySelector('#polizaVer');
        polizaVer.addEventListener("click", e=>this.verPoliza(poliza));
        
        rows.append(tr);
    }
    
    verPoliza=async(poliza)=> {
        
        let datosPoliza = `
        
            <div class="input-group mb-3">
                                <span class="input-group-text">Codigo</span>
                                <input type="text" class="form-control" id="dpCodigo" readonly>
                            </div>
        
                            <div class="input-group mb-3">
                                <span class="input-group-text">Numero de placa</span>
                                <input type="text" class="form-control" id="dpPlaca" readonly>
                            </div>   
        
                            <div class="input-group mb-3">
                                <span class="input-group-text">Fecha de vigencia</span>
                                <input type="text" class="form-control" id="dpFechaVigencia" readonly>
                            </div> 
        
                            <div class="input-group mb-3">
                                <span class="input-group-text">Marca</span>
                                <input type="text" class="form-control" id="dpMarca" readonly>
                            </div>
        
                            <div class="input-group mb-3">
                                <span class="input-group-text">Modelo</span>
                                <input type="text" class="form-control" id="dpModelo" readonly>
                            </div>
        
                            <div class="input-group mb-3">
                                <span class="input-group-text">Valor</span>
                                <input type="text" class="form-control" id="dpValor" readonly>
                            </div>
        
                            <div class="input-group mb-3">
                                <span class="input-group-text">Plazo de pago</span>
                                <input type="text" class="form-control" id="dpPlazoPago" readonly>
                            </div>
        
                            <div class="input-group mb-3">
                                <span class="input-group-text">Anio</span>
                                <input type="text" class="form-control" id="dpAnio" readonly>
                            </div>
        
                            <div class="input-group mb-3">
                                <span class="input-group-text">Coberturas</span>
                                <input type="text" class="form-control" id="dpCoberturas" readonly>
                            </div>

        `;
        
        let boton=``;
        this.dom.querySelector('#cliente #modalDatos #formDatos #closeDatos').replaceChildren();
        this.dom.querySelector('#cliente #modalDatos #formDatos #closeDatos').innerHTML = boton;
        
        this.dom.querySelector('#cliente #modalDatos #formDatos #modalBody').replaceChildren();
        this.dom.querySelector('#cliente #modalDatos #formDatos #modalBody').innerHTML = datosPoliza;
        
        let urlParams = new URL(backend+'/cliente/getPolizaById');
        urlParams.searchParams.append('idPoliza', poliza.cod);
        urlParams.searchParams.append('idCliente', globalstate.session.cedula);
        
        const request = new Request(urlParams, {
            method: 'GET',
            headers: {}
        });
        
        try{
            
            const response = await fetch(request);
            if (!response.ok) {
                errorMessage(response.status);
                return;
            }
            
            const datosPoliza = await response.json();
            
            document.getElementById('dpCodigo').value = datosPoliza.cod;
            document.getElementById('dpPlaca').value = datosPoliza.numPlaca;
            document.getElementById('dpFechaVigencia').value = datosPoliza.fechavigencia;
            document.getElementById('dpMarca').value = datosPoliza.modelo.marca.marca;
            document.getElementById('dpModelo').value = datosPoliza.modelo.modelo;
            document.getElementById('dpValor').value = datosPoliza.valor;
            
            console.log(datosPoliza.plazopago);
            
            switch(datosPoliza.plazopago) {
                case 1:
                    document.getElementById('dpPlazoPago').value = 'Trimestral';
                  break;
                case 2:
                    document.getElementById('dpPlazoPago').value = 'Semestral';
                  break;
                case 3:
                    document.getElementById('dpPlazoPago').value = 'Anual';
                  break;
                default:
            }
            
            document.getElementById('dpAnio').value = datosPoliza.anio;
            
            let coberturas = '';

            for (const cobertura of datosPoliza.coberturas) {
              coberturas += cobertura.detalle + ', ';
            }

            coberturas = coberturas.slice(0, -2);
            
            document.getElementById('dpCoberturas').value = coberturas;
            
        } catch (error) {
            console.error(error);
        }
        
        this.modalDatos.show();
        
    }
    
    //////////////////////////////////////
    
    getCategorias=()=>{
        
        let urlParams = new URL(backend+'/cliente/getCategorias');

        const request = new Request(urlParams, {
            method: 'GET',
            headers: {}
        });
        
        (async()=> {
            let response = await fetch(request);
            if (!response.ok) { 
                alert('Error al cargar categorias'); 
                return; 
            }
            
            const categorias = await response.json();
            
            let formCoberturas = this.dom.querySelector('#cliente #modalNuevaPoliza #modalCoberturasContent #formCoberturas');
            formCoberturas.replaceChildren();
            formCoberturas.innerHTML = "";
            
            for (const categoria of categorias) {
                formCoberturas.innerHTML += `
                        <h5>${categoria.detalle}</h5>
                `;
                
                for (const cobertura of categoria.cobertura) {
                    formCoberturas.innerHTML += `
                        <div class="form-check">
                          <input class="form-check-input" type="checkbox" name="cobertura" id="${cobertura.cod}">
                          <label class="form-check-label" for="checkbox${cobertura.cod}">${cobertura.detalle}</label>
                        </div>
                    `;
                }
            }
            
        })();
    }
    
    getMarcas=()=>{
        
        let urlParams = new URL(backend+'/cliente/getMarcas');

        const request = new Request(urlParams, {
            method: 'GET',
            headers: {}
        });
        
        (async()=> {
            let response = await fetch(request);
            if (!response.ok) { 
                alert('Error al cargar categorias'); 
                return; 
            }
            
            const marcas = await response.json();
            
            let comboMarcasModelos = this.dom.querySelector('#cliente #modalNuevaPoliza #modalDatosBasicosContent #formDatosBasicos #comboModelos');
            comboMarcasModelos.replaceChildren();
            comboMarcasModelos.innerHTML = "";
            
            for (const marca of marcas) {
                comboMarcasModelos.innerHTML += `
                        <option data-tokens="marca" disabled style="font-weight: bold; font-size: 16px;">${marca.marca}</option>
                `;
                
                for (const modelo of marca.modelos) {
                    comboMarcasModelos.innerHTML += `
                        <option id="${modelo.cod}">${modelo.modelo}</option>
                    `;
                }
            }
            
        })();
    
    }
    
    getCostoPoliza=async()=>{
        
        let formCoberturas = this.dom.querySelector("#cliente #modalNuevaPoliza #modalCoberturasContent #formCoberturas");
        const checkboxes = formCoberturas.querySelectorAll('input[type="checkbox"]');
        
        let coberturas = [];

        for (const checkbox of checkboxes) {
            if (checkbox.checked) {
              coberturas.push(checkbox.id);
            }
        }
        
        ///////////////////////////////////////////

        let urlParams = new URL(backend+'/cliente/getCostoPoliza');
        urlParams.searchParams.append('valor', document.getElementById('formDatosBasicos').querySelector('#valor').value);

        const request = new Request(urlParams, {
            method: 'POST',
            headers: { 'Content-Type': 'application/json'
            },
            body: JSON.stringify(coberturas)
        });

        let response = await fetch(request);
        if (!response.ok) { 
            alert('Error al calcular costo');
            return;
        }

        const costo = await response.json();
        
        let formPago = this.dom.querySelector('#cliente #modalNuevaPoliza #modalPagoContent #formPago');
        formPago.replaceChildren();
        formPago.innerHTML = "";
        
        formPago.innerHTML += `
            <div class="input-group mb-3">
                <span class="input-group-text">Costo</span>
                <input type="text" class="form-control" id="costo" name="costo" value="${costo}" readonly>
            </div>
        
        `;
    }
    
    comprar=async()=>{
        const formDatosBasicos = document.getElementById('formDatosBasicos');
        const formCoberturas = document.getElementById('formCoberturas');
        
        const coberturas = [];
        const checkboxes = formCoberturas.querySelectorAll('input[type="checkbox"]');
        
        for (const checkbox of checkboxes) {
            if (checkbox.checked) {
              coberturas.push(checkbox.id);
            }
        }

        ///////////////////////////////////////////////////////////
        
        let urlParams = new URL(backend+'/cliente/guardarPoliza');
        urlParams.searchParams.append('numPlaca', formDatosBasicos.querySelector('#numPlaca').value);
        urlParams.searchParams.append('fechaVigencia', formDatosBasicos.querySelector('#fechaVigencia').value);
        urlParams.searchParams.append('idModelo', formDatosBasicos.querySelector('#comboModelos option:checked').id);
        urlParams.searchParams.append('anio', formDatosBasicos.querySelector('#anio').value);
        urlParams.searchParams.append('valor', formDatosBasicos.querySelector('#valor').value);
        urlParams.searchParams.append('plazoPago', formDatosBasicos.querySelector('input[name="metodoPago"]:checked').value);
        urlParams.searchParams.append('idCliente', globalstate.session.cedula);
        console.log(urlParams);
        
        const request = new Request(urlParams, {
            method: 'POST',
            headers: { 
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(coberturas)
        });

        let response = await fetch(request);
        if (!response.ok) { 
            alert('Error al comprar poliza');
            return;
        }
        
        this.dimissCompra();
        this.listPolizas();
    }
    
    //////////////////////////////////////
    
    //////////////////////////////////////
    
    emptyEntity=()=>{}
    
}
