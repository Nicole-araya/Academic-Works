class Pcr {
  dom;
  resultados;
  constructor() {
    this.dom = this.body();
    this.dom
      .querySelector(".semaphore")
      ?.addEventListener("click", (e) => this.openPopUp());
    this.dom
      .querySelector("#cerrarPopUp")
      ?.addEventListener("click", (e) => this.closePopUp());
    this.resultados = [0, 0, 0];
    //---------------------------------------------------
    this.leerDatos("P","php/leerPlaneacion.php");
    this.leerDatos("C","php/leerCalidad.php");
    this.leerDatos("R","php/leerRiesgos.php");
    //---------------------------------------------------
    
  }

  body = () => {
    let html = `
        ${this.render()}
        ${this.popUp()}
        `;
    var rootContent = document.createElement("div");
    rootContent.id = "preguntas";
    rootContent.innerHTML = html;
    return rootContent;
  };

  render = () => {
    return `<div id="tablas"> </div>`;
  };

  openPopUp = () => {
    let popup = document.getElementById("semaphore-popUp");
    let resultadoPopUp = document.getElementById("resultado-popUp");
    let imagePopUp = document.getElementById("semaphore-img");
    let resultImg = "";
    let resultadoDiv = "";

    popup.style.display = "block";
    fondoOscuro.style.display = "block";

    let promedio =
      (this.resultados[0] + this.resultados[1] + this.resultados[2]) / 3;
    promedio = parseFloat(promedio).toFixed(2);

    if (promedio <= 30 && promedio >= 0) {
      resultadoDiv =
        '<div class="red-light">Promedio total= ' + promedio + "</div>";
      resultImg = '<img src="img/red.png">';
    }
    if (promedio <= 69 && promedio >= 31) {
      resultadoDiv =
        '<div class="yellow-light">Promedio total= ' + promedio + "</div>";
      resultImg = '<img src="img/yellow.png">';
    }
    if (promedio >= 70) {
      resultadoDiv =
        '<div class="green-light">Promedio total= ' + promedio + "</div>";
      resultImg = '<img src="img/green.png">';
    }
    resultadoPopUp.innerHTML = resultadoDiv;
    imagePopUp.innerHTML = resultImg;
  };

  closePopUp = () => {
    let popup = document.getElementById("semaphore-popUp");

    popup.style.display = "none";
    fondoOscuro.style.display = "none";
  };

  popUp = () => {
    return `
    <button class="semaphore">
    <i class="fa-solid fa-traffic-light"></i>
    </button>

    <div id="semaphore-popUp">
        <div id="semaphore-img"></div>
        <p id="resultado-popUp"></p>
        <center>
            <button id="cerrarPopUp">Cerrar</button>
        </center>
    </div>

    <div id="fondoOscuro"></div>
    `;
  };

  actualizarResultado = (resultado, divId) => {
    var divResultado = document.getElementById(divId);
    resultado = parseFloat(resultado).toFixed(2);
    var resultHTML = "";

    if (resultado <= 30 && resultado >= 0) {
      resultHTML =
        "<div id=" +
        divResultado.id +
        ' class="red-bar">Resultado del cálculo: ' +
        resultado +
        "</div>";
    }
    if (resultado <= 70 && resultado >= 31) {
      resultHTML =
        "<div id=" +
        divResultado.id +
        ' class="yellow-bar">Resultado del cálculo: ' +
        resultado +
        "</div>";
    }
    if (resultado > 71) {
      resultHTML =
        "<div id=" +
        divResultado.id +
        ' class="green-bar">Resultado del cálculo: ' +
        resultado +
        "</div>";
    }
    var nuevoDiv = document.createElement("div");
    nuevoDiv.innerHTML = resultHTML;

    divResultado.parentNode.replaceChild(nuevoDiv, divResultado);
  };

  renderPreguntas = (tipo, preguntas) => {
    let formId = "";
    let barId = "";
    let enunciado = "";
    let posArray = 0;
    if(tipo === "P"){
        formId = "formPlaneacion";
        barId = "resCalculoPlaneacion";
        enunciado = "Planeacion";
        posArray = 0;
    }
    if(tipo === "C"){
        formId = "formCalidad";
        barId = "resCalculoCalidad";
        enunciado = "Calidad";
        posArray = 1;
    }
    if(tipo === "R"){
        formId = "formRiesgos";
        barId = "resCalculoRiesgos";
        enunciado = "Riesgos";
        posArray = 2;
    }
    let resultHTML = `
        <center>
        <form method="post" action="" id=${formId}>
            <table>
                <tr>
                    <th class="enunciado">Preguntas sobre ${enunciado}</th>
                    <th>Sí</th>
                    <th>No</th>
                    <th>N/A</th>
                </tr>
                ${preguntas.map((pregunta, num) => `
                <tr>
                    <td> <input type="hidden" name="p${num + 1}" value="${pregunta.DESCRIPCION}">
                    ¿${pregunta.DESCRIPCION}
                    </td>
                    <td><input type="radio" name="r${num + 1}" value="1"></td>
                    <td><input type="radio" name="r${num + 1}" value="0"></td>
                    <td><input type="radio" name="r${num + 1}" value="2"></td>
                </tr>`).join('')}
            </table>
            <div id=${barId} class="red-bar">
                Resultado del cálculo: 0
            </div>
            <input type="submit" name="submit" value="Enviar respuestas">

        </form>
    `;
    let newForm = document.createElement("div");
    newForm.innerHTML = resultHTML;

    this.dom.querySelector("#tablas").appendChild(newForm);

    this.dom
      .querySelector(`#${formId}`)
      ?.addEventListener("submit", (e) => {
        e.preventDefault(); // Evita el envío del formulario por defecto
        this.enviarDatos(
          `#${formId}`,
          barId,
          posArray
        );
      });
  };

  enviarDatos = async (formId, divId, num) => {
    try {
      let data = this.dom.querySelector(`${formId}`);
      let form = new FormData(data);
      const response = await fetch("php/calculoRespuestas.php", {
        method: "POST",
        body: form,
      });
      if (response.ok) {
        const resultado = await response.json();
        this.resultados[num] = resultado;
        this.actualizarResultado(resultado, divId);
      } else {
        console.log("Error");
      }
    } catch (error) {
      console.log(error);
    }
  };
  
  leerDatos = async (tipo, php) => {
    try {
      const response = await fetch(php);
      if (response.ok) {
        const resultado = await response.json();
        this.renderPreguntas(tipo, resultado);
      } else {
        console.log("Error");
      }
    } catch (error) {
      console.log(error);
    }
  };
  
}
