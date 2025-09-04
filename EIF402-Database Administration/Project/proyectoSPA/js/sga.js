class SGA {
  dom;
  constructor() {
    this.dom = this.body();
    this.leerSQL();
    this.leerCBLog();
    this.leerCacheBuffer();
  }

  body = () => {
    let html = `
    ${this.render()}`;
    let rootContent = document.createElement("div");
    rootContent.id = "sga";
    rootContent.innerHTML = html;
    return rootContent;
  };

  render = () => {
    return `
    <div class="container-grid1">
      <div id="grafica1">
        <canvas id="graphicChart">
        </canvas>
      </div>
      <div id="cblog"></div>
    </div>
    <div id="detalles"></div>
    <div id="consultas"></div>
    `;
  };

  renderSentences = (consultas) => {
    let html = `
    <h2>Consultas en la base de datos</h2>
    <table>
      <tr>
        <th>ID process</th>
        <th>Load Time</th>
        <th>SQL Text</th>
        <th>USER</th>
      </tr>
      ${consultas
        .map(
          (consulta) => `
      <tr>
        <td>${consulta.IDPROCESS}</td>
        <td>${consulta.FIRST_LOAD_TIME}</td>
        <td>${consulta.SQLTEXT}</td>
        <td>${consulta.PARSEUSER}</td>
      </tr>`
        )
        .join("")}
    </table>
    <br>
    `;

    let newForm = document.createElement("div");
    newForm.innerHTML = html;

    this.dom.querySelector("#consultas").appendChild(newForm);
  };

  renderCBLog = (cblog) => {
    let html = "";
    cblog[0] !== undefined
      ? (html = `
      <h2>Registros en CBLog</h2>
      <table>
        <tr>
          <th>Load Time</th>
          <th>ID Process</th>
          <th>User</th>
          <th>SQL Text</th>
        </tr>
        ${cblog
          .map(
            (cb) => `
        <tr>
          <td>${cb.FECHA_HORA}</td>
          <td>${cb.IDPROCESS}</td>
          <td>${cb.LOG_USER}</td>
          <td>${cb.SQL_DETAIL}</td>
        </tr>`
          )
          .join("")}
      </table>
      <br>
      `)
      : (html = `
      <h2>Registros en CBLog</h2>
      <table>
        <tr>
          <th>Detalle</th>
        </tr
        <tr>
          <td>Actualmente no se ha superado el 85% de la base de datos</td>
        </tr>
      </table>
      <br>`);

    let newForm = document.createElement("div");
    newForm.innerHTML = html;

    this.dom.querySelector("#cblog").appendChild(newForm);
  };

  renderGraphicDetails = (detalles) => {
    let html = `
    <h2>Detalles de la base de datos</h2>
    <table>
      <tr>
        <th>Load Time</th>
        <th>Total Size</th>
        <th>Free Space</th>
        <th>Used Size</th>
      </tr>
      ${detalles
        .map(
          (detalle, num) => `
      <tr>
        <td>${detalle.FECHA_HORA}</td>
        <td>${detalle.TOTAL_SIZE_MB}MB</td>
        <td>${detalle.FREE_SPACE_MB}MB</td>
        <td>${detalle.USED_SIZE_MB}MB</td>
      </tr>`
        )
        .join("")}
    </table>
    <br>
    `;

    let newForm = document.createElement("div");
    newForm.innerHTML = html;

    this.dom.querySelector("#detalles").appendChild(newForm);
  };

  renderGrafica = (detalles) => {
    const ctx = this.dom.querySelector("#graphicChart");
    const index = detalles.length - 1;
    const fecha = detalles[index].FECHA_HORA;
    const usedSize = parseFloat(detalles[index].USED_SIZE_MB);
    const HWMVal = parseFloat(detalles[index].TOTAL_SIZE_MB * 0.85);
    let supera =
      (parseFloat(detalles[index].USED_SIZE_MB) / parseFloat(detalles[index].TOTAL_SIZE_MB)) *
        100 >
        85
        ? true
        : false;

    new Chart(ctx, {
      type: "bar",
      data: {
        datasets: [
          {
            label: "Consumo de la base de datos",
            data: [usedSize],
            backgroundColor: function (context) {
              return supera ? "rgb(185, 83, 83)" : "rgb(103, 185, 83)";
            },
            borderSkipped: false,
          },
        ],
        labels: [fecha],
      },
      options: {
        scales: {
          y: {
            beginAtZero: true,
          },
        },
        plugins: {
          tooltip: {
            callbacks: {
              label: function (context) {
                return supera
                  ? "Se ha superado en 85% la capacidad de la base de datos"
                  : "La base de datos no ha superado el 85%";
              },
            },
          },
          annotation: {
            annotations: {
              horizontalLine: {
                type: "line",
                mode: "horizontal",
                scaleID: "y",
                value: HWMVal, // Valor en el eje Y donde deseas la línea horizontal
                borderColor: "rgb(214, 96, 96)",
                borderWidth: 2,
              },
            },
          },
        },
        maintainAspectRatio: false,
      },
    });

  };

  leerSQL = async () => {
    try {
      const response = await fetch("php/sqltext.php");
      if (response.ok) {
        const resultado = await response.json();
        this.renderSentences(resultado);
      } else {
        console.log("Error");
      }
    } catch (error) {
      console.log(error);
    }
  };
  
  leerCacheBuffer = async () => {
    try {
      const response = await fetch("php/cachebuffer.php");
      if (response.ok) {
        const resultado = await response.json();
        this.renderGraphicDetails(resultado);
        this.renderGrafica(resultado);
      } else {
        console.log("Error");
      }
    } catch (error) {
      console.log(error);
    }
  };
  
  leerCBLog = async () => {
    try {
      const response = await fetch("php/CBLog.php");
      if (response.ok) {
        const resultado = await response.json();
        this.renderCBLog(resultado);
      } else {
        console.log("Error");
      }
    } catch (error) {
      console.log(error);
    }
  };  

}
