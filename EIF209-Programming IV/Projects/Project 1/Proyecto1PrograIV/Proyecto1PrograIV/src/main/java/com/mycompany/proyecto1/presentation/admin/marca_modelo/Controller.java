/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package com.mycompany.proyecto1.presentation.admin.marca_modelo;

import com.mycompany.proyecto1.logic.Service;
import jakarta.servlet.ServletException;
import jakarta.servlet.ServletOutputStream;
import jakarta.servlet.annotation.MultipartConfig;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.FileInputStream;
import java.io.IOException;



/**
 *
 * @author Nicole
 */
@MultipartConfig()@WebServlet(name = "ControllerAdminMarcaModelo", urlPatterns = {"/presentation/admin/marca_modelo/show","/presentation/admin/marca_modelo/image"})
public class Controller extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        request.setAttribute("model", new Model());
        
        String viewUrl="";     
        switch (request.getServletPath()) {
          case "/presentation/admin/marca_modelo/show":
              viewUrl = this.show(request);
              break;
          case "/presentation/admin/marca_modelo/image":
              this.getImage(request,response);
              break;
        }          
        request.getRequestDispatcher(viewUrl).forward( request, response); 
    }

    private String show(HttpServletRequest request) {
        return showAction(request);
    }

    private String showAction(HttpServletRequest request) {
        Model model = (Model) request.getAttribute("model");
        Service service = Service.instance();
        
        try {                                                 
            model.setMarcas(service.getMarcasModelo());
            
            return "/presentation/admin/marca_modelo/View.jsp";     //VIEW
        } catch (Exception ex) {
            return "";
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
    
 public static final String LOCATION="C:/Proyecto/seguros/";
    private void getImage(HttpServletRequest request,HttpServletResponse response){
    String id= request.getParameter("idFld"); //hay que poner esta parte
    try{
    
        ServletOutputStream os= response.getOutputStream();
        FileInputStream is= new FileInputStream(LOCATION+id);
        is.transferTo(os);
        os.close();
        
    }catch(IOException ex){}
    }
}
