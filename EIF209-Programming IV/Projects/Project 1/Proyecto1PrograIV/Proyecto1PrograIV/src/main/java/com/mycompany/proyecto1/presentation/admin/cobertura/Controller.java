/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package com.mycompany.proyecto1.presentation.admin.cobertura;

import com.mycompany.proyecto1.logic.Categoria;
import com.mycompany.proyecto1.logic.Service;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;


/**
 *
 * @author Nicole
 */
@WebServlet(name = "ControllerCobertura", urlPatterns = {"/presentation/admin/cobertura/show","/presentation/admin/cobertura/add"})
public class Controller extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        request.setAttribute("model", new Model());
        
        String viewUrl="";     
        switch (request.getServletPath()) {
          case "/presentation/admin/cobertura/show":
              viewUrl = this.show(request);    
              break;
          case "/presentation/admin/cobertura/add":
              viewUrl = this.add(request);    
              break;

        }          
        request.getRequestDispatcher(viewUrl).forward( request, response); 
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

    private String show(HttpServletRequest request) {
         return showAction(request);
    }

    private String showAction(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance();
        try { 
           
           model.setCategorias(service.getCategorias());
           
           return "/presentation/admin/cobertura/View.jsp";     // VIEW
        } catch (Exception ex) {
            return "/presentation/Error.jsp";
        }
    }

    private String add(HttpServletRequest request) {
        try{
            Map<String,String> errores =  this.validarAdd(request); 
            if(errores.isEmpty()){
                this.updateModel(request);          
                return this.addAction(request);
            }
            else{
                request.setAttribute("errores", errores);
                return "/presentation/admin/cobertura/View.jsp";    
            }            
        }
        catch(Exception e){
            return "/presentation/Error.jsp";             
        }   
    }

    private Map<String, String> validarAdd(HttpServletRequest request) {
      Map<String,String> errores = new HashMap<>();
      
        if (request.getParameter("descripcionFld").isEmpty()) {
            errores.put("descripcionFld", "Descrpcion requerida");
        }
        return errores;
    }

    private void updateModel(HttpServletRequest request) {
    Model model= (Model) request.getAttribute("model");

    model.getSeleccionado().setDetalle(request.getParameter("descripcionFld"));
    }

    private String addAction(HttpServletRequest request) {
      Model model = (Model) request.getAttribute("model");
      Service service = Service.instance();
      String codCateg= request.getParameter("categCombox");
        try { 
           model.getSeleccionado().setCategoria(service.categoriaFind(codCateg));
           model.getSeleccionado().setCostoMinimo(Integer.valueOf(request.getParameter("costoFld")));
           model.getSeleccionado().setPorcentaje(Integer.valueOf(request.getParameter("porcentajeFld")));
           service.agregarCobertura(model.getSeleccionado());
           return "/presentation/admin/categ_cober/show";
        } catch (Exception ex) {
            return "/presentation/Error.jsp";
        }
    }

}
