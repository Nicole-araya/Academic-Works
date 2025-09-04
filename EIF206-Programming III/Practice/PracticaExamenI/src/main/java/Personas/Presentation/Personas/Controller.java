package Personas.Presentation.Personas;

import Personas.Application;
import Personas.Logic.Persona;
import Personas.Logic.Service;
import com.itextpdf.io.font.constants.StandardFonts;
import com.itextpdf.io.image.ImageDataFactory;
import com.itextpdf.kernel.colors.Color;
import com.itextpdf.kernel.colors.ColorConstants;
import com.itextpdf.kernel.font.PdfFont;
import com.itextpdf.kernel.font.PdfFontFactory;
import com.itextpdf.kernel.pdf.PdfDocument;
import com.itextpdf.kernel.pdf.PdfWriter;
import com.itextpdf.layout.Document;
import com.itextpdf.layout.borders.Border;
import com.itextpdf.layout.element.Cell;
import com.itextpdf.layout.element.Image;
import com.itextpdf.layout.element.Paragraph;
import com.itextpdf.layout.element.Table;
import com.itextpdf.layout.properties.HorizontalAlignment;
import com.itextpdf.layout.properties.TextAlignment;

import java.util.List;

public class Controller {

    View view;
    Model model;
    public Controller(View view,Model model){
        model.setPersonas(Service.instance().personaSearch(""));
        this.view=view;
        this.model=model;
        view.setController(this);
        view.setModel(model);
    }

    public void preAgregar(){
        Application.personaController.preagregar();
    }
    public void buscar(String filtro){
        List<Persona> rows=Service.instance().personaSearch(filtro);
        model.setPersonas(rows);
        model.commit();
    }

    public void editar(int row){
        String id=model.getPersonas().get(row).getId();
        Persona per=null;
        try{
            per=Service.instance().getPersona(id);
            Application.personaController.editar(per);
        } catch (Exception e) {}
    }
    public void borrar(int row){
        String id=model.getPersonas().get(row).getId();
        Persona per=null;
        try{
            per=Service.instance().getPersona(id);
            Service.instance().personaDelete(per);
            this.buscar("");
        } catch (Exception e) {}
    }
    public void show(){
        Application.window.setContentPane(view.getPanel());
    }

    private Cell getCell(Paragraph paragraph, TextAlignment alignment, boolean hasBorder) {
        Cell cell = new Cell().add(paragraph);
        cell.setPadding(0);
        cell.setTextAlignment(alignment);
        if(!hasBorder) cell.setBorder(Border.NO_BORDER);
        return cell;
    }

    private Cell getCell(Image image, HorizontalAlignment alignment, boolean hasBorder) {
        Cell cell = new Cell().add(image);
        image.setHorizontalAlignment(alignment);
        cell.setPadding(0);
        if(!hasBorder) cell.setBorder(Border.NO_BORDER);
        return cell;
    }

    public void imprimir()throws Exception{
        String dest="Personas.pdf";
        PdfFont font = PdfFontFactory.createFont(StandardFonts.HELVETICA);
        PdfWriter writer = new PdfWriter(dest);
        PdfDocument pdf = new PdfDocument(writer);

        //Document document = new Document(pdf, PageSize.A4.rotate());
        Document document = new Document(pdf);
        document.setMargins(20, 20, 20, 20);

        Table header = new Table(1);
        header.setWidth(400);
        header.setHorizontalAlignment(HorizontalAlignment.CENTER);
        header.addCell(getCell(new Paragraph("PDF_de_Personas").setFont(font).setBold().setFontSize(20f), TextAlignment.CENTER,false));
        header.addCell(getCell(new Image(ImageDataFactory.create("src/main/java/Personas/recursos/img.png")), HorizontalAlignment.CENTER,false));
        document.add(header);

        document.add(new Paragraph(""));document.add(new Paragraph(""));

        Color bkg = ColorConstants.BLUE;
        Color frg= ColorConstants.WHITE;
        Table body = new Table(5);
        body.setWidth(400);
        body.setHorizontalAlignment(HorizontalAlignment.CENTER);
        body.addCell(getCell(new Paragraph("ID").setBackgroundColor(bkg).setFontColor(frg),TextAlignment.CENTER,true));
        body.addCell(getCell(new Paragraph("Nombre").setBackgroundColor(bkg).setFontColor(frg),TextAlignment.CENTER,true));
        body.addCell(getCell(new Paragraph("Edad").setBackgroundColor(bkg).setFontColor(frg),TextAlignment.CENTER,true));
        body.addCell(getCell(new Paragraph("Sexo").setBackgroundColor(bkg).setFontColor(frg),TextAlignment.CENTER,true));
        body.addCell(getCell(new Paragraph("Estado Civil").setBackgroundColor(bkg).setFontColor(frg),TextAlignment.CENTER,true));

        for(Persona p: model.getPersonas()){
            body.addCell(getCell(new Paragraph(p.getId()),TextAlignment.CENTER,true));
            body.addCell(getCell(new Paragraph(p.getNombre()),TextAlignment.CENTER,true));
            body.addCell(getCell(new Paragraph(String.valueOf(p.getEdad())),TextAlignment.CENTER,true));
            body.addCell(getCell(new Paragraph(p.getSexo()),TextAlignment.CENTER,true));
            body.addCell(getCell(new Paragraph(p.getEstCivil()),TextAlignment.CENTER,true));

        }
        document.add(body);
        document.close();
    }
}
