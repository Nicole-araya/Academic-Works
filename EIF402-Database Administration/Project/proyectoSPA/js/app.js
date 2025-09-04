class App {
  dom;
  pcr;
  sga;
  contTs;
  respaldos;

  constructor() {
    this.dom = this.render();
    this.renderButtonOptions();
    this.renderHeader();
    this.pcr = new Pcr();
    this.sga = new SGA();
    this.contTs = new ContTablespaces();
    this.respaldos = new Respaldos();
  }

  render = () => {
    const html = `
            ${this.renderBody()} 
          `;
    var rootContent = document.createElement("div");
    rootContent.id = "app";
    rootContent.innerHTML = html;
    return rootContent;
  };

  renderButtonOptions = () => {
    let html = `
        <button id="PCR">Planeacion-Calidad-Riesgos</button>
        <button id="SGA">SGA de la BD</button>
        <button id="ContTs">Control TableSpaces</button>
        <button id="Respaldos">Generar Respaldos</button>
    `;
    this.dom.querySelector("#opciones").replaceChildren();
    this.dom.querySelector("#opciones").innerHTML = html;

    this.dom
      .querySelector("#PCR")
      ?.addEventListener("click", (e) => this.showPCR());
    this.dom
      .querySelector("#SGA")
      ?.addEventListener("click", (e) => this.showSGA());
    this.dom
      .querySelector("#ContTs")
      ?.addEventListener("click", (e) => this.showContTs());
    this.dom
      .querySelector("#Respaldos")
      ?.addEventListener("click", (e) => this.showRespaldos());
  };

  renderHeader = () => {
    let html = `
        <h1>Control Interno en los Sistemas Gestores de Bases de Datos</h1>
        <button id="About">Acerca De</button>
          `;

    this.dom.querySelector("#encabezado").replaceChildren();
    this.dom.querySelector("#encabezado").innerHTML = html;

    this.dom
      .querySelector("#About")
      ?.addEventListener("click", (e) => this.showAbout());
  };

  renderBody = () => {
    return `
    <div id="encabezado"></div>
    <div id="opciones"></div>
    ${this.renderBodyInfo()}
    </div>    
       `;
  };

  renderBodyInfo = () => {
    return `
    <div id = "body">
    <div class = "infoContainer">
      <div>
        Los controles internos en los sistemas gestores de bases de datos son cruciales para proteger la seguridad de los datos, mantener su integridad, garantizar la disponibilidad y confiabilidad de la información, cumplir con regulaciones legales y mejorar la eficiencia operativa de las organizaciones. Estos controles son esenciales para el funcionamiento exitoso de las bases de datos en el entorno empresarial.
      </div>
      <img src="img/basemini.png"
      </div>
    </div>

    `;
  }

  showPCR = () => {
    this.dom.querySelector("#body").replaceChildren(this.pcr.dom);
    this.pcr.body();
  };

  showSGA = () => {
    this.dom.querySelector("#body").replaceChildren(this.sga.dom);
    this.sga.body();
  };
  showContTs = () => {
    this.dom.querySelector("#body").replaceChildren(this.contTs.dom);
    this.contTs.body();
  };
  showRespaldos = () => {
    this.dom.querySelector("#body").replaceChildren(this.respaldos.dom);
    this.respaldos.body();
  };
  showAbout = () => {
    let html = `
      <div class="acercaDe">
        <h2>Administracion de Bases de Datos Ciclo II - 2023</h2>
        <h2>Estudiantes:</h2>
        <div><i class="fa-regular fa-user"></i><p>Nicole Araya Ballestero</p></div>
        <div><i class="fa-regular fa-user"></i><p>Ariana Solano Vallejos</p></div>
        <h2>Profesor:</h2>
        <div><i class="fa-solid fa-person-chalkboard"></i><p>Msc. Johnny Villalobos Murillo</p></div>
      </div>
    `;
    this.dom.querySelector("#body").replaceChildren();
    this.dom.querySelector("#body").innerHTML = html;
    return html;
  };
}
