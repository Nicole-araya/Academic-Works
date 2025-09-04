package sucursales.presentation.sucursales;

import sucursales.Application;
import sucursales.logic.Sucursal;
import sucursales.logic.Service;
import java.util.List;

import com.itextpdf.io.font.constants.StandardFonts;
import com.itextpdf.io.image.ImageData;
import com.itextpdf.io.image.ImageDataFactory;
import com.itextpdf.kernel.colors.Color;
import com.itextpdf.kernel.colors.ColorConstants;
import com.itextpdf.kernel.font.PdfFont;
import com.itextpdf.kernel.font.PdfFontFactory;
import com.itextpdf.kernel.geom.PageSize;
import com.itextpdf.kernel.pdf.PdfDocument;
import com.itextpdf.kernel.pdf.PdfWriter;
import com.itextpdf.layout.Document;
import com.itextpdf.layout.borders.Border;
import com.itextpdf.layout.element.*;
import com.itextpdf.layout.properties.HorizontalAlignment;
import com.itextpdf.layout.properties.TextAlignment;
import com.itextpdf.layout.properties.VerticalAlignment;

public class Controller {
    View view;
    Model model;

    public Controller(sucursales.presentation.sucursales.View view, sucursales.presentation.sucursales.Model model) {
        model.setSucursales(Service.instance().sucursalesSearchName(""));
        this.view = view;
        this.model = model;
        view.setController(this);
        view.setModel(model);
    }
    public void buscar(String filtro){
        List<Sucursal> rows = Service.instance().sucursalesSearchName(filtro);
        model.setSucursales(rows);
        model.commit();
    }

    public void preAgregar(){

        Application.sucursalController.preAgregar();
    }


    public void editar(int row){
        String cod = model.getSucursales().get(row).getID();
        Sucursal s=null;
        try {
            s= Service.instance().getSucursal(cod);
            Application.sucursalController.editar(s);
        } catch (Exception ex) {}
    }

    public void borrar(int row){
        String cod = model.getSucursales().get(row).getID();
        Sucursal s=null;
        try {
            s= Service.instance().getSucursal(cod);
            Service.instance().sucursalDelete(s);
            this.buscar("");
        } catch (Exception ex) {}
    }

    public void show(){
        Application.window.setContentPane(view.getPanel());
    }
    private Cell getCell( Paragraph paragraph,TextAlignment alignment,boolean hasBorder) {
        Cell cell = new Cell().add(paragraph);
        cell.setPadding(0);
        cell.setTextAlignment(alignment);
        if(!hasBorder) cell.setBorder(Border.NO_BORDER);
        return cell;
    }

    private Cell getCell( Image image,HorizontalAlignment alignment,boolean hasBorder) {
        Cell cell = new Cell().add(image);
        image.setHorizontalAlignment(alignment);
        cell.setPadding(0);
        if(!hasBorder) cell.setBorder(Border.NO_BORDER);
        return cell;
    }

    public void imprimir()throws Exception{
        String dest="Sucursales.pdf";
        PdfFont font = PdfFontFactory.createFont(StandardFonts.HELVETICA);
        PdfWriter writer = new PdfWriter(dest);
        PdfDocument pdf = new PdfDocument(writer);

        //Document document = new Document(pdf, PageSize.A4.rotate());
        Document document = new Document(pdf);
        document.setMargins(20, 20, 20, 20);

        Table header = new Table(1);
        header.setWidth(400);
        header.setHorizontalAlignment(HorizontalAlignment.CENTER);
        header.addCell(getCell(new Paragraph("Sistema Integrado SISE").setFont(font).setBold().setFontSize(20f), TextAlignment.CENTER,false));
        header.addCell(getCell(new Image(ImageDataFactory.create("src/main/java/recursos/imag.png")), HorizontalAlignment.CENTER,false));
        document.add(header);

        document.add(new Paragraph(""));document.add(new Paragraph(""));

        Color bkg = ColorConstants.BLUE;
        Color frg= ColorConstants.WHITE;
        Table body = new Table(4);
        body.setWidth(400);
        body.setHorizontalAlignment(HorizontalAlignment.CENTER);
        body.addCell(getCell(new Paragraph("ID").setBackgroundColor(bkg).setFontColor(frg),TextAlignment.CENTER,true));
        body.addCell(getCell(new Paragraph("Referencia").setBackgroundColor(bkg).setFontColor(frg),TextAlignment.CENTER,true));
        body.addCell(getCell(new Paragraph("Direccion").setBackgroundColor(bkg).setFontColor(frg),TextAlignment.CENTER,true));
        body.addCell(getCell(new Paragraph("Zonaje").setBackgroundColor(bkg).setFontColor(frg),TextAlignment.CENTER,true));
        for(Sucursal s: model.getSucursales()){
            body.addCell(getCell(new Paragraph(s.getID()),TextAlignment.CENTER,true));
            body.addCell(getCell(new Paragraph(s.getReferencia()),TextAlignment.CENTER,true));
            body.addCell(getCell(new Paragraph(s.getDireccion()),TextAlignment.CENTER,true));
            body.addCell(getCell(new Paragraph(String.valueOf(s.getZonaje())),TextAlignment.CENTER,true));
        }
        document.add(body);
        document.close();
    }
}