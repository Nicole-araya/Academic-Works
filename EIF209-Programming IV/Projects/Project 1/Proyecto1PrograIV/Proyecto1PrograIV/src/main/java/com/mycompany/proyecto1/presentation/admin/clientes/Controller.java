/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package com.mycompany.proyecto1.presentation.admin.clientes;

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
@WebServlet(name = "ControllerAdminClientes", urlPatterns = {"/presentation/admin/clientes/show"})
public class Controller extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
     request.setAttribute("model", new Model());
        
        String viewUrl="";     
        switch (request.getServletPath()) {
          case "/presentation/admin/clientes/show":
              viewUrl = this.show(request);
              break;
         /* case "/presentation/admin/clientes/polizas":
              viewUrl = this.polizas(request);
              break;*/
        }          
        request.getRequestDispatcher(viewUrl).forward( request, response); 
  }

    public String show(HttpServletRequest request) {
        return this.showAction(request);
    }
    
    public String showAction(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance(); 
        HttpSession session = request.getSession(true);
        Usuario usuario = (Usuario) session.getAttribute("usuario"); 
        try {  
            model.setAdmin(service.adminFind(usuario));
            model.setClientes(service.getClientesPoliza());
            return "/presentation/admin/clientes/View.jsp";     //VIEW
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

   /* private String polizas(HttpServletRequest request) {
        //creo que no lo vamos a utilizar
        try
         {
            Map<String,String> errores =  this.validar(request); 
            if(errores.isEmpty()){
                this.updateModel(request);          
                return this.polizasAction(request);
            }
            else{
                request.setAttribute("errores", errores);
                return "/presentation/admin/clientes/Polizas.jsp";    
            }            
        }
        catch(Exception e){
            return "/presentation/Error.jsp";             
        }   

    }
    
    private Map<String, String> validar(HttpServletRequest request) {
      Map<String,String> errores = new HashMap<>();
        
        if (request.getParameter("idButton").isEmpty()){
            errores.put("idButton","ID requerida");
        }  
        return errores;
    }

    private void updateModel(HttpServletRequest request) {
      Model model= (Model) request.getAttribute("model");
      model.getSeleccionado().getUser().setCedula(request.getParameter("idButton"));
    }

    private String polizasAction(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance();   
        Cliente cliente;
        
        try {
            cliente = service.clienteFind(model.getSeleccionado().getUser());
        } catch (Exception ex) {
            cliente=null;
        }
        try {        
            model.setPolizas(service.polizasFind(cliente));
            return "/presentation/admin/clientes/Polizas.jsp";     //VIEW
        } catch (Exception ex) {
            return "";
        }
    }*/
}
