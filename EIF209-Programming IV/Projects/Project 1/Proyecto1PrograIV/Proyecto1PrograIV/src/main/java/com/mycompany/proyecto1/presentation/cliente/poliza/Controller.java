/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.cliente.poliza;

import com.mycompany.proyecto1.logic.Service;
import com.mycompany.proyecto1.logic.Cliente;
import com.mycompany.proyecto1.logic.Cobertura;
import com.mycompany.proyecto1.logic.Poliza;
import com.mycompany.proyecto1.logic.Usuario;
import jakarta.servlet.ServletException;
import jakarta.servlet.ServletOutputStream;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Nicole
 */
@WebServlet(name = "ClientePolizaController", urlPatterns = {"/presentation/cliente/poliza/show",
                                                             "/presentation/cliente/poliza/add1",
                                                             "/presentation/cliente/poliza/details",
                                                             "/presentation/cliente/poliza/add2",
                                                             "/presentation/cliente/poliza/add3"})
public class Controller extends HttpServlet {
    
  protected void processRequest(HttpServletRequest request, 
                                HttpServletResponse response)
         throws ServletException, IOException {
           
        request.setAttribute("model", new Model());
        
        String viewUrl="";     
        switch (request.getServletPath()) {
          case "/presentation/cliente/poliza/show":
              viewUrl = this.show(request);     //pantalla de agregar
              break;
          case "/presentation/cliente/poliza/details":
              viewUrl = this.details(request);  //detalles de una poliza selecionada
              break;
                                                            
          case "/presentation/cliente/poliza/add1":
              viewUrl = this.agregar(request);  //va hacia agregar covertura
              break;
          case "/presentation/cliente/poliza/add2":
              viewUrl = this.cobertura(request);    //covertura
              break;
          case "/presentation/cliente/poliza/add3":
              viewUrl = this.compra(request);    //facturaaa, agrega poliza
              break;
        }          
        request.getRequestDispatcher(viewUrl).forward( request, response); 
  }

    public String show(HttpServletRequest request) {

        return showAction(request);
    }
    
     public String cobertura(HttpServletRequest request) {
        /*try{
            Map<String,String> errores =  this.validarAddCober(request);
            if(errores.isEmpty()){
                    
                return this.addCoberAction(request);
            }
            else{
                request.setAttribute("errores", errores);
                return "/presentation/cliente/poliza/AgregarCober.jsp";    // VIEW VEEERR 
            }            
        }
        catch(Exception e){
            return "/presentation/Error.jsp";             
        }   */
        return this.addCoberAction(request);
    }
     
    Map<String,String> validarAddCober(HttpServletRequest request){
       Map<String,String> errores = new HashMap<>();

        if (request.getParameter("CobFld").isEmpty()){
            errores.put("coberFld","Seleccion requerida");
        }
       
        return errores;
    }

    
    //AGARRA EL CODIGO DE ESA POLIZA ALEATORIO
    Map<String,String> validarAdd(HttpServletRequest request){

       Map<String,String> errores = new HashMap<>();
        
        if (request.getParameter("placaFld").isEmpty()){
            errores.put("placaFld","Numero de placa requerida");
        }
        if (request.getParameter("anioFld").isEmpty()){
            errores.put("anioFld","Anio requerida");
        }
        if (request.getParameter("valorFld").isEmpty()){
            errores.put("valorFld","Valor requerida");
        }
        if (request.getParameter("plazoFld").isEmpty()){
            errores.put("plazoFld","Plazo de pago requerido");
        }
        if (request.getParameter("fechaVigenciaFld").isEmpty()){
            errores.put("fechaVigenciaFld","Fecha requerida");
        }
        
        return errores;
    }

    void updateModel(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");

        model.getCurrent().setNumPlaca(request.getParameter("placaFld"));         
        model.getCurrent().setAnio(Integer.parseInt(request.getParameter("anioFld")));
        model.getCurrent().setValor(Integer.parseInt(request.getParameter("valorFld")));
        model.getCurrent().setPlazopago(Integer.parseInt(request.getParameter("plazoFld")));
        model.getCurrent().setFechavigencia(request.getParameter("fechaVigenciaFld"));
    }  

    public String showAction(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance();
       
        try {        
             model.setMarcas(service.getMarcasModelo());
             model.setCategorias(service.getCategoriaCober());
            return "/presentation/cliente/poliza/Agregar.jsp";     // VIEW
        } catch (Exception ex) {
            return "/presentation/Error.jsp";
        }
    }
    
    public String agregar(HttpServletRequest request) {
        try{
            Map<String,String> errores =  this.validarAdd(request); //ESTE VALIDAR SE ENCARGA DE VER SI ESTA VACIO
            if(errores.isEmpty()){
                this.updateModel(request);          
                return this.addAction(request);
            }
            else{
                request.setAttribute("errores", errores);
                
                return "/presentation/cliente/poliza/Agregar.jsp";    // VEEER AQUI VIEW
            }            
        }
        catch(Exception e){
            return "/presentation/Error.jsp";             
        }   
    }
    
    public String addAction(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance();
        HttpSession session = request.getSession(true);
        Usuario usuario = (Usuario) session.getAttribute("usuario");       
        String codigoModelo = request.getParameter("modeloFld");
        
        try {
            model.getCurrent().setCliente(service.clienteFind(usuario));
            model.getCurrent().setModelo(service.modeloFind(codigoModelo));
            model.setCategorias(service.getCategoriaCober());
            
            if (model.getCurrent().getCliente() == null) {
                throw new Exception("No existe cliente");
            }
            session.setAttribute("poliza", model.getCurrent());  
            return "/presentation/cliente/poliza/AgregarCober.jsp";     // VIEW
        } catch (Exception ex) {
            return "/presentation/Error.jsp";
        }
    }
        
        public String addCoberAction(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance();
        HttpSession session = request.getSession(true);
        Poliza poliza = (Poliza) session.getAttribute("poliza");
        String coberturaCodigo = request.getParameter("coberFld");
        Cobertura cobertura;
 
        try {  
           model.setCurrent(poliza);
           cobertura = service.coberturaFind(coberturaCodigo);
           model.getCurrent().setCobertura(cobertura);
           model.getCurrent().setCategoria(cobertura.getCategoria());
           model.getCurrent().getCosto();
           session.setAttribute("poliza", model.getCurrent()); 
           //service.agregarPoliza(model.getCurrent()); //agrego la poliza y con sus categorias y coberturas listas
           
           return "/presentation/cliente/poliza/Compra.jsp";     // VIEW
        } catch (Exception ex) {
            return "/presentation/Error.jsp";
        }
    }
    
   
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

    private String details(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance();
        try {
            model.setCurrent(service.polizaFind(request.getParameter("codigoPoliza")));
            return "/presentation/cliente/poliza/View.jsp";
        } catch (Exception ex) {
            return "/presentation/login/Error.jsp";
        }
    }
    
    public static final String LOCATION="C:/Proyecto/seguros/";
    private void getImage(HttpServletRequest request,HttpServletResponse response){
        
    String id= request.getParameter(""); //hay que poner esta parte
    try{
    
        ServletOutputStream os= response.getOutputStream();
        FileInputStream is= new FileInputStream(LOCATION+id);
        is.transferTo(os);
        os.close();
        
    }catch(IOException ex){}
    }

    private String compra(HttpServletRequest request) {
        return compraAction(request);
    }

    private String compraAction(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance();
        HttpSession session = request.getSession(true);
        Poliza poliza = (Poliza) session.getAttribute("poliza");
 
        try {  
           model.setCurrent(poliza);
           service.agregarPoliza(model.getCurrent()); //agrego la poliza 
           
           return "/presentation/cliente/polizas/show";     // VIEW
        } catch (Exception ex) {
            return "/presentation/Error.jsp";
        }
    }
    
}
