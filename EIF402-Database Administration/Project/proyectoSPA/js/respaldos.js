class Respaldos {
  dom;
  detalles = [];
  constructor() {
    this.dom = this.body();
    this.renderButtonOptions();
    this.renderRespaldoInfo();
    this.dom
      .querySelector("#cerrarPopUp")
      ?.addEventListener("click", (e) => this.closePopUp());
  }

  body = () => {
    let html = `
      ${this.render()}`;
    let rootContent = document.createElement("div");
    rootContent.id = "respaldos";
    rootContent.innerHTML = html;
    return rootContent;
  };

  render = () => {
    return `
    <div id="opciones-res"></div>
    <div id = "respaldos-space"></div>
    ${this.renderPopUp("")}
    `;
  };

  renderPopUp = (respuesta) => {
    return `
    <div id="respuestaPopUp">

      <label>${respuesta}</label>

      <div class="buttons">
        <button id="cerrarPopUp">OK</button>
      </div>

    </div>

    <div id="fondoOscuro"></div>
    `;
  };

  openPopUp = (respuesta) => {
    let popup = document.getElementById("respuestaPopUp");
    let fondoOscuro = document.getElementById("fondoOscuro");

    document.querySelector("#respuestaPopUp label").textContent = respuesta;

    popup.style.display = "block";
    fondoOscuro.style.display = "block";
  };

  closePopUp = () => {
    let popup = document.getElementById("respuestaPopUp");

    popup.style.display = "none";
    fondoOscuro.style.display = "none";
  };

  renderRespaldoInfo = () => {
    let html = `
    <div class = "infoContainer">
      <div>
      Respaldar bases de datos utilizando Oracle Recovery Manager (RMAN) es crucial debido a su eficiencia y coherencia en la creación de copias de seguridad, permitiendo la continuidad de las operaciones mientras se respalda la base de datos. Además, RMAN simplifica la recuperación en caso de fallos, ya que mantiene un registro completo de las copias de seguridad, garantizando la integridad de los datos y minimizando el tiempo de inactividad en situaciones de pérdida de datos, fallos de hardware o errores humanos.
      </div>
      <img src="img/respaldosmini.png">
    </div>
    `;

    this.dom.querySelector("#respaldos-space").replaceChildren();
    this.dom.querySelector("#respaldos-space").innerHTML = html;
  };

  renderButtonOptions = () => {
    let html = `
        <button id="NuevoRespaldo">Generar nuevo respaldo</button>
        <button id="VerRespaldo">Ver respaldos generados</button>
    `;
    this.dom.querySelector("#opciones-res").replaceChildren();
    this.dom.querySelector("#opciones-res").innerHTML = html;

    this.dom
      .querySelector("#NuevoRespaldo")
      ?.addEventListener("click", (e) => this.renderNomRutaScript());
    this.dom
      .querySelector("#VerRespaldo")
      ?.addEventListener("click", (e) => this.leerDatosBackup());
  };

  renderScriptsGenerados = (respaldos) => {
    let html = `
    <center>
      <h2>Scripts de respaldo generados</h2>
      <table>
      <tr>
      <th>Nombre</th>
      <th>Ruta</th>
      <th>Tipo de backup</th>
      <th></th>
      <th></th>
      
      ${respaldos
        .map(
          (e) =>
            `
          </tr>
            <td>${e.NOMBRERESPALDO}</td>
            <td>${e.RUTASCRIPT}</td>
            ${
              e.TIPO == "1" ? "<td>Full Backup</td>" : "<td>Partial Backup</td>"
            }
            <td>
              <button id=${e.RUTAABSOLUTA} tipo="${
              e.TIPO
            }" class="ejecutarButton">Ejecutar</button>
            </td>
            <td>
            <button class="borrar" id=${
              e.RUTAABSOLUTA
            }><i class="fa-solid fa-trash"></i></button>
            </td>
          <tr>`
        )
        .join("")}
      </table>
    </center>
    `;

    this.dom.querySelector("#respaldos-space").innerHTML = html;

    const botones = this.dom.querySelectorAll(".ejecutarButton");
    botones.forEach((boton) => {
      boton?.addEventListener("click", (event) => {
        const tipo = event.currentTarget.getAttribute("tipo");
        const ruta = event.target.id;

        if (tipo === "1") {
          this.generarFullBackup(ruta);
        } else if (tipo === "2") {
          this.generarPartialBackup(ruta);
        }
      });
    });

    const borrares = this.dom.querySelectorAll(".borrar");
    borrares.forEach((boton) => {
      boton?.addEventListener("click", (event) => {
        const ruta = event.target.id;

        this.borrarRespaldo(ruta);
      });
    });
  };

  renderNomRutaScript = () => {
    let html = `
    <div class = "formContainer">
      <div class="scriptForm">
        
          <label id="infoNombre">Ingrese el nombre del respaldo que desea generar:</label>
          <input type="text" id="nombreRespaldo" placeholder="Nombre del respaldo">
            <div>
              <label> 
                  <input type="radio" name="tipoRespaldo" value="1" checked> Realizar FullBackup
              </label>
              <label> 
                  <input type="radio" name="tipoRespaldo" value="2"> Realizar PartialBackup
              </label>
            </div>
            <label id="infoRuta">Ingrese la ruta donde desea guardar el respaldo:</label>
            <input type="text" id="rutaRespaldo" placeholder="Ruta respaldo">

            <label id="infoScript">Ingrese la ruta donde desea guardar los scripts para generar los respaldos:</label>
            <input type="text" id="rutaScript" placeholder="Ruta script">

            <div class="buttons">
              <button id="confirmar">Confirmar</button>
            </div>
            <div class="progressBar">
              <progress value="0" max="100"></progress>
            </div>
      </div>
    </div>
    `;
    this.dom.querySelector("#respaldos-space").innerHTML = html;

    this.dom
      .querySelector("#confirmar")
      ?.addEventListener("click", (e) => this.nomRutaScript());
  };

  nomRutaScript = () => {
    let nombreRespaldoInput = this.dom.querySelector("#nombreRespaldo");
    let rutaRespaldoInput = this.dom.querySelector("#rutaRespaldo");
    let rutaScriptInput = this.dom.querySelector("#rutaScript");

    let nombreInputValue = nombreRespaldoInput.value.trim();
    let rutaInputValue = rutaRespaldoInput.value.trim();
    let rutaScriptValue = rutaScriptInput.value.trim();

    let infoNombre = this.dom.querySelector("#infoNombre");
    let infoRuta = this.dom.querySelector("#infoRuta");
    let infoScript = this.dom.querySelector("#infoScript");

    let nombreRespaldo = "";
    let rutaRespaldo = "";
    let rutaScript = "";

    nombreInputValue == ""
      ? (infoNombre.classList.add("error"),
        nombreRespaldoInput.classList.add("errorBorder"))
      : (infoNombre.classList.remove("error"),
        nombreRespaldoInput.classList.remove("errorBorder"),
        (nombreRespaldo = nombreInputValue));

    rutaInputValue == ""
      ? (infoRuta.classList.add("error"),
        rutaRespaldoInput.classList.add("errorBorder"))
      : (infoRuta.classList.remove("error"),
        rutaRespaldoInput.classList.remove("errorBorder"),
        (rutaRespaldo = rutaInputValue));

    rutaScriptValue == ""
      ? (infoScript.classList.add("error"),
        rutaScriptInput.classList.add("errorBorder"))
      : (infoScript.classList.remove("error"),
        rutaScriptInput.classList.remove("errorBorder"),
        (rutaScript = rutaScriptValue));
    nombreRespaldo && rutaRespaldo && rutaScript != ""
      ? this.dom.querySelector('input[name="tipoRespaldo"]:checked').value == 1
        ? this.renderFBInputs(rutaRespaldo, nombreRespaldo, rutaScript, 1)
        : this.renderPBInputs(rutaRespaldo, nombreRespaldo, rutaScript, 2)
      : "";
  };

  renderFBInputs = (rutaRespaldo, nombreRespaldo, rutaScript, tipo) => {
    let html = `
    <div class = "formContainer">
      <div class="scriptForm">
        <label id="infoSpfile">Ingrese la ruta donde desea guardar el spfile:</label>
        <input type="text" id="rutaSpfile" placeholder="Ruta spfile">

        <label id="infoControl">Ingrese la ruta donde desea guardar el controlFile:</label>
        <input type="text" id="rutaControl" placeholder="Ruta controlFile">

        <label id="infoBitacora">Ingrese la ruta donde desea guardar la bitacora:</label>
        <input type="text" id="rutaBitacora" placeholder="Ruta bitacora">
        
        <div class="buttons">
          <button id="confirmar">Generar</button>
          <button id="atras">Volver</button>
        </div>

        <div class="progressBar">
            <progress value="50" max="100"></progress>
        </div>
      </div>
    </div>
`;

    this.dom.querySelector("#respaldos-space").innerHTML = html;

    this.dom
      .querySelector("#confirmar")
      ?.addEventListener("click", (e) =>
        this.fBInputs(rutaRespaldo, nombreRespaldo, rutaScript, tipo)
      );
    this.dom
      .querySelector("#atras")
      ?.addEventListener("click", (e) => this.renderNomRutaScript());
  };

  renderPBInputs = async (rutaRespaldo, nombreRespaldo, rutaScript, tipo) => {
    let TSNames = await this.leerTSNames();

    let html = `
    <div class = "formContainer">
      <div class="scriptForm">
        <label>Si desea guardar el spfile, ingrese la ruta donde desea guardarlo:</label>
        <input type="text" id="rutaSpfile" placeholder="Ruta spfile">

        <label>Si desea guardar el controlFile, ingrese la ruta donde desea guardarlo:</label>
        <input type="text" id="rutaControl" placeholder="Ruta controlFile">

        <label id="infoBitacora">Ingrese la ruta donde desea guardar la bitacora:</label>
        <input type="text" id="rutaBitacora" placeholder="Ruta bitacora">

        <label id="infoTS">Seleccione el nombre de los tablespaces que desea respaldar:</label>
       
        <div id="inputContainer">
             ${TSNames.map(
               (e) =>
                 `<label>${e.TABLESPACE_NAME}<input type="checkbox" value="${e.TABLESPACE_NAME}"></label>`
             ).join("")}
        </div>

        <div class="buttons">
          <button id="confirmar">Generar</button>
          <button id="atras">Volver</button>
        </div>

        <div class="progressBar">
            <progress value="50" max="100"></progress>
        </div>

      </div>
    </div>
`;

    this.dom.querySelector("#respaldos-space").innerHTML = html;

    this.dom
      .querySelector("#confirmar")
      ?.addEventListener("click", (e) =>
        this.pBInputs(rutaRespaldo, nombreRespaldo, rutaScript, tipo)
      );
    this.dom
      .querySelector("#atras")
      ?.addEventListener("click", (e) => this.renderNomRutaScript());
  };

  leerTSNames = () => {
    return fetch("php/leerTSNames.php", {
      method: "GET",
    })
      .then((response) => {
        if (response.ok) {
          return response.json();
        } else {
          throw new Error("Error");
        }
      })
      .catch((error) => {
        console.log(error);
      });
  };

  pBInputs = (rutaRespaldo, nombreRespaldo, rutaScript, tipo) => {
    let infoTS = this.dom.querySelector("#infoTS");
    let infoBitacora = this.dom.querySelector("#infoBitacora");

    let rutaBitacoraInput = this.dom.querySelector("#rutaBitacora");
    let rutaBitacoraValue = rutaBitacoraInput.value.trim();

    let rutaBitacora = "";
    let rutaSpfile = this.dom.querySelector("#rutaSpfile").value.trim();
    let rutaControl = this.dom.querySelector("#rutaControl").value.trim();
    let data;

    rutaBitacoraValue == ""
      ? (infoBitacora.classList.add("error"),
        rutaBitacoraInput.classList.add("errorBorder"))
      : (infoBitacora.classList.remove("error"),
        rutaBitacoraInput.classList.remove("errorBorder"),
        (rutaBitacora = rutaBitacoraValue));

    const camposTS = document.querySelectorAll('input[type="checkbox"]');
    let cumpleMinimo = false;
    let nombresTS = [];

    camposTS.forEach((campo) => {
      campo.checked
        ? ((cumpleMinimo = true),
          nombresTS.push(campo.value),
          infoTS.classList.remove("error"))
        : infoTS.classList.add("error");
    });

    rutaBitacora != "" && cumpleMinimo
      ? ((data = {
          rutaRespaldo: rutaRespaldo,
          nombreRespaldo: nombreRespaldo,
          rutaScript: rutaScript,
          rutaSpfile: rutaSpfile,
          rutaBitacora: rutaBitacora,
          rutaControl: rutaControl,
          nombresTS: nombresTS,
          tipo: tipo,
        }),
        this.guardarScripts(data))
      : "";
  };

  fBInputs = (rutaRespaldo, nombreRespaldo, rutaScript, tipo) => {
    let infoSpfile = this.dom.querySelector("#infoSpfile");
    let infoControl = this.dom.querySelector("#infoControl");
    let infoBitacora = this.dom.querySelector("#infoBitacora");

    let rutaSpfileInput = this.dom.querySelector("#rutaSpfile");
    let rutaControlInput = this.dom.querySelector("#rutaControl");
    let rutaBitacoraInput = this.dom.querySelector("#rutaBitacora");

    let rutaSpfileValue = rutaSpfileInput.value.trim();
    let rutaControlValue = rutaControlInput.value.trim();
    let rutaBitacoraValue = rutaBitacoraInput.value.trim();

    let rutaSpfile = "";
    let rutaControl = "";
    let rutaBitacora = "";
    let data;

    rutaSpfileValue == ""
      ? (infoSpfile.classList.add("error"),
        rutaSpfileInput.classList.add("errorBorder"))
      : (infoSpfile.classList.remove("error"),
        rutaSpfileInput.classList.remove("errorBorder"),
        (rutaSpfile = rutaSpfileValue));

    rutaControlValue == ""
      ? (infoControl.classList.add("error"),
        rutaControlInput.classList.add("errorBorder"))
      : (infoControl.classList.remove("error"),
        rutaControlInput.classList.remove("errorBorder"),
        (rutaControl = rutaControlValue));

    rutaBitacoraValue == ""
      ? (infoBitacora.classList.add("error"),
        rutaBitacoraInput.classList.add("errorBorder"))
      : (infoBitacora.classList.remove("error"),
        rutaBitacoraInput.classList.remove("errorBorder"),
        (rutaBitacora = rutaBitacoraValue));

    rutaSpfile && rutaControl && rutaBitacora != ""
      ? ((data = {
          rutaRespaldo: rutaRespaldo,
          nombreRespaldo: nombreRespaldo,
          rutaScript: rutaScript,
          rutaSpfile: rutaSpfile,
          rutaBitacora: rutaBitacora,
          rutaControl: rutaControl,
          nombresTS: [],
          tipo: tipo,
        }),
        this.guardarScripts(data))
      : "";
  };

  renderOK = () => {
    let html = `
    <div class = "formContainer">
      <div class="scriptForm">
          <label>Respaldo generado con exito, dirijase a Ver respaldos generados para ejecutar.</label>

          <div class="buttons">
            <button id="confirmar">OK</button>
          </div>

          <div class="progressBar">
            <progress value="100" max="100"></progress>
          </div>
      </div>
    </div>
    `;
    this.dom.querySelector("#respaldos-space").innerHTML = html;

    this.dom
      .querySelector("#confirmar")
      ?.addEventListener("click", (e) => this.renderNomRutaScript());
  };

  guardarScripts = (data) => {
    fetch("php/guardarScripts.php", {
      method: "POST",
      body: JSON.stringify(data),
    })
      .then((response) => {
        if (response.ok) {
          this.renderOK();
        } else {
          console.log("Error");
        }
      })
      .catch((error) => {
        console.log(error);
      });
  };

  leerDatosBackup = async () => {
    try {
      const response = await fetch("php/leerScripts.php");

      if (response.ok) {
        const resultado = await response.json();
        this.renderScriptsGenerados(resultado);
      } else {
        throw new Error("Error");
      }
    } catch (error) {
      console.log(error);
    }
  };

  leerDatosById = (ruta) => {
    return fetch("php/leerScriptsId.php", {
      method: "POST",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded",
      },
      body: "ruta=" + ruta,
    })
      .then((response) => {
        if (response.ok) {
          return response.json();
        } else {
          throw new Error("Error");
        }
      })
      .catch((error) => {
        console.log(error);
      });
  };

  generarBackup = async (ruta, scriptName) => {
    try {
      let data = await this.leerDatosById(ruta);
      let response = await fetch("php/" + scriptName, {
        method: "POST",
        body: JSON.stringify(data[0]),
      });
      if (response.ok) {
        let resultado = await response.json();
        this.openPopUp(resultado.message);
      } else {
        this.openPopUp("Error");
      }
    } catch (error) {
      console.log(error);
    }
  };

  generarFullBackup = (ruta) => {
    this.generarBackup(ruta, "scriptFullBackup.php");
  };

  generarPartialBackup = (ruta) => {
    this.generarBackup(ruta, "scriptPartialBackup.php");
  };

  borrarRespaldo = async (ruta) => {
    try {
      const response = await fetch("php/borrarRespaldo.php", {
        method: "POST",
        headers: {
          "Content-Type": "application/x-www-form-urlencoded",
        },
        body: "ruta=" + ruta,
      });

      if (response.ok) {
        const resultado = await response.json();
        this.openPopUp(resultado.message);
        this.leerDatosBackup();
      } else {
        console.log("Error");
      }
    } catch (error) {
      console.log(error);
    }
  };
}
