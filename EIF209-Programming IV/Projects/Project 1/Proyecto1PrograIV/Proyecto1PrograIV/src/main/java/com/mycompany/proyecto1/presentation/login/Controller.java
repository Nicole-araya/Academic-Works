/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.login;

import com.mycompany.proyecto1.logic.Cliente;
import com.mycompany.proyecto1.logic.Service;
import com.mycompany.proyecto1.logic.Usuario;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author Nicole
 */
@WebServlet(name = "LoginController", urlPatterns = {"/presentation/login/show","/presentation/login/login","/presentation/login/logout","/presentation/login/registerBlank",
                                                    "/presentation/login/registerAdd"})
public class Controller extends HttpServlet {

  protected void processRequest(HttpServletRequest request, 
                                HttpServletResponse response)
         throws ServletException, IOException {
      
        request.setAttribute("model", new Model()); 
        
        String viewUrl="";
        switch(request.getServletPath()){
            case "/presentation/login/show":
                viewUrl=this.show(request);
                break;              
            case "/presentation/login/login":
                viewUrl=this.login(request);
                break;            
            case "/presentation/login/logout":
                viewUrl=this.logout(request);
                break;
            case "/presentation/login/registerBlank":
                viewUrl=this.register(request);
                break;
                case "/presentation/login/registerAdd":
                viewUrl=this.registerAdd(request);
                break;
        }
        request.getRequestDispatcher(viewUrl).forward( request, response); 
  }

    private String login(HttpServletRequest request) { 
        try{
            Map<String,String> errores =  this.validar(request);
            if(errores.isEmpty()){
                this.updateModel(request);          
                return this.loginAction(request);
            }
            else{
                request.setAttribute("errores", errores);
                return "/presentation/login/View.jsp"; 
            }            
        }
        catch(Exception e){
            return "/presentation/login/Error.jsp";             
        }         
    }
    
    Map<String,String> validar(HttpServletRequest request){
        Map<String,String> errores = new HashMap<>();
        if (request.getParameter("cedulaFld").isEmpty()){
            errores.put("cedulaFld","Cedula requerida");
        }

        if (request.getParameter("claveFld").isEmpty()){
            errores.put("claveFld","Clave requerida");
        }
        return errores;
    }
    
    void updateModel(HttpServletRequest request){
        Model model = (Model) request.getAttribute("model");

        model.getCurrent().setCedula(request.getParameter("cedulaFld"));
        model.getCurrent().setClave(request.getParameter("claveFld"));
        //model.getCurrent().setTipo(Integer.parseInt(request.getParameter("tipo")));
   }

        
    public String loginAction(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance();
        HttpSession session = request.getSession(true);
        String viewUrl="";
        try {
            Usuario real = service.usuarioFind(model.getCurrent().getCedula());
            session.setAttribute("usuario", real); //usersssh
            switch(real.getTipo()){
                case 1:
                    viewUrl="/presentation/cliente/polizas/show"; //CLIENTE
                    break;
                case 2:
                     viewUrl="/presentation/admin/blank/show"; //ADMINISTRADOR-MENU 
                    break;             
            }
            return viewUrl;
        } catch (Exception ex) {
            Map<String,String> errores = new HashMap<>();
            request.setAttribute("errores", errores);
            errores.put("cedulaFld","Usuario o clave incorrectos");
            errores.put("claveFld","Usuario o clave incorrectos");
            return "/presentation/login/View.jsp"; //VIEW
        }        
    }   

    public String logout(HttpServletRequest request){
        return this.logoutAction(request);
    }
    
    public String logoutAction(HttpServletRequest request){
        HttpSession session = request.getSession(true);
        session.removeAttribute("usuario");
        session.invalidate();
        return "/presentation/Index.jsp"; //VIEW   
        //return "/presentation/login/show";
    }

    public String show(HttpServletRequest request){
        return this.showAction(request);
    }
        
    public String showAction(HttpServletRequest request){
        Model model = (Model) request.getAttribute("model");
        model.getCurrent().setCedula("");
        model.getCurrent().setClave("");
        return "/presentation/login/View.jsp"; //VIEW
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

    private String register(HttpServletRequest request) {             
        return this.registerAction(request);      

    }
    
    private String registerAction(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        model.getCurrent().setCedula("");
        model.getCurrent().setClave("");
        return "/presentation/register/View.jsp"; 
    }
    
    Map<String,String> validarRegister(HttpServletRequest request){
        Map<String,String> errores = new HashMap<>();
        if (request.getParameter("cedulaFld").isEmpty()){
            errores.put("cedulaFld","Cedula requerida");
        }
        if (request.getParameter("claveFld").isEmpty()){
            errores.put("claveFld","Clave requerida");
        }
        if (request.getParameter("nombreFld").isEmpty()){ 
            errores.put("nombreFld","Nombre requerido");
        }
        if (request.getParameter("telefonoFld").isEmpty()){ 
            errores.put("telefonoFld","Telefono requerido");
        }
        if (request.getParameter("correoFld").isEmpty()){ 
            errores.put("correoFld","Correo requerido");
        }
        if (request.getParameter("pagoFld").isEmpty()){ 
            errores.put("pagoFld","Metodo de Pago requerido");
        }
        return errores;
    }

    private String registerAdd(HttpServletRequest request) {
        try{
            Map<String,String> errores =  this.validarRegister(request);
            if(errores.isEmpty()){
                this.updateModel(request);          
                return this.registerAddAction(request);
            }
            else{
                request.setAttribute("errores", errores);
                return "/presentation/login/View.jsp"; 
            }            
        }
        catch(Exception e){
            return "/presentation/Error.jsp";             
        }   
    }

    private String registerAddAction(HttpServletRequest request) {   //ENTRA CUANDO TODOS LOS DATOS ESTAN Y SI SE AGREGA DE UNA GUARDA USUARIO Y ENTRA AL SISTEMA POLIZAS
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance();
        HttpSession session = request.getSession(true);
        try {
            if (service.usuarioFind(model.getCurrent().getCedula())!=null){    //SI EXISTE SE SALE
                throw new Exception("Existe cliente");}

            Usuario real = new Usuario(model.getCurrent().getCedula(),model.getCurrent().getClave(),1); //pongo 1 porque es un cliente
            session.setAttribute("usuario", real); //usersssh
            
            Cliente cliente=new Cliente(real,request.getParameter("nombreFld"),request.getParameter("telefonoFld"),request.getParameter("correoFld"),request.getParameter("pagoFld"));
            service.agregarCliente(cliente);
            
            return "/presentation/cliente/polizas/show";
            
        } catch (Exception ex) {                                
            Map<String,String> errores = new HashMap<>();
            request.setAttribute("errores", errores);
            errores.put("cliente","Cliente existe");
            
            return "/presentation/Error.jsp"; //VIEW
        }  
    }

    

    
}
