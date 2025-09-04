class ContTablespaces {
  dom;
  constructor() {
    this.dom = this.body();
    this.leerControlesTs();
    this.leerDatosGrafica();
  }

  body = () => {
    let html = `
      ${this.render()}`;
    let rootContent = document.createElement("div");
    rootContent.id = "contTs";
    rootContent.innerHTML = html;
    return rootContent;
  };

  render = () => {
    return `
      <div id="container-grid2">
        <div id="grafica2">
        <canvas id="graphicChart">
        </canvas>
        </div>
        <div id="detalles"></div>
      </div>
      <div id="controles"></div>
      `;
  };

  renderGrafica = (detalles) => {
    const ctx = this.dom.querySelector("#graphicChart");
    let tsName = [];
    let usedSize = [];
    let freeSize = [];
    let supera = [];
    let hwm = [];
    detalles.map((e) => {
      tsName.push(`${e.TABLESPACE_NAME} ${e.MB_TAMANO} MB`);
      usedSize.push(parseFloat(e.MB_USADOS.replace(',', '.')));
      hwm.push(parseFloat(e.MB_TAMANO.replace(',', '.') * 0.85));
      freeSize.push(parseFloat(e.MB_LIBRES.replace(',', '.')));
      supera.push(parseFloat(e.MB_USADOS.replace(',', '.') / e.MB_TAMANO.replace(',', '.')) * 100 > 85);
    });
    

    new Chart(ctx, {
      type: "bar",
      data: {
        datasets: [
          {
            label: "Tamaño consumido",
            data: [...usedSize],
            stack: "stack1",
            backgroundColor: function (context) {
              const index = context.dataIndex;
              return supera[index] ? "rgb(185, 83, 83)" : "rgb(103, 185, 83)";
            },
          },
          {
            label: "Tamaño libre",
            data: [...freeSize],
            stack: "stack1",
            backgroundColor: "rgb(153, 153, 153)",
          },
          {
            label: "HWM",
            data: [...hwm],
            backgroundColor: "rgb(0,0,0,0)",
            borderColor: "rgb(214, 96, 96)",
            borderWidth: {top: 0, left: 0, right: 4, bottom: 4},
            stack: "stack2"
          }
        ],
        labels: [...tsName],
      },
      options: {
        indexAxis: "y",
        responsive: true,
        maintainAspectRatio: false,
        scales: {
          x: {
            stacked: true,
          },
          y: {
            stacked: true,
          },
        },
        plugins: {
          tooltip: {
            callbacks: {
              label: function (context) {
                const dataIndex = context.dataIndex;
                return supera[dataIndex]
                  ? "Se ha superado en 85% la capacidad de la base de datos"
                  : "La base de datos no ha superado el 85%";
              },
            },
          },
        },
      },
    });
  };

  renderDetallesGrafica = (detalles) => {
    let html = `
    <h2>Detalles de los Tablespaces</h2>
    <table>
      <tr>
        <th>Tablespace Name</th>
        <th>State</th>
        <th>Total Size</th>
        <th>Used Size</th>
        <th>Free Size</th>
      </tr>
      ${detalles
        .map(
          (detalle) => `
      <tr>
        <td>${detalle.TABLESPACE_NAME}</td>
        <td>${detalle.Estado}</td>
        <td>${detalle.MB_TAMANO} MB</td>
        <td>${detalle.MB_USADOS} MB</td>
        <td>${detalle.MB_LIBRES} MB</td>
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

  renderControl = (contoles) => {
    let html = `
    <h2>Control de los Tablespaces</h2>
    <table>
      <tr>
        <th>Load Time</th>
        <th>Tablespace Name</th>
        <th>Used Size</th>
        <th>Days left</th>
      </tr>
      ${contoles
        .map(
          (control) => `
      <tr>
        <td>${control.FECHA_ALERTA}</td>
        <td>${control.TABLESPACE_NAME}</td>
        <td>${control.MBUSADOS} MB</td>
        <td>${control.DIAS}</td>
      </tr>`
        )
        .join("")}
    </table>
    <br>
    `;

    let newForm = document.createElement("div");
    newForm.innerHTML = html;

    this.dom.querySelector("#controles").appendChild(newForm);
  };

  leerControlesTs = async () => {
    try {
      const response = await fetch("php/leerControlesTs.php");
      if (response.ok) {
        const resultado = await response.json();
        this.renderControl(resultado);
      } else {
        console.log("Error");
      }
    } catch (error) {
      console.log(error);
    }
  };
  
  leerDatosGrafica = async () => {
    try {
      const response = await fetch("php/leerDatosGrafica.php");
      if (response.ok) {
        const resultado = await response.json();
        this.renderGrafica(resultado);
        this.renderDetallesGrafica(resultado);
      } else {
        console.log("Error");
      }
    } catch (error) {
      console.log(error);
    }
  };
  
}
