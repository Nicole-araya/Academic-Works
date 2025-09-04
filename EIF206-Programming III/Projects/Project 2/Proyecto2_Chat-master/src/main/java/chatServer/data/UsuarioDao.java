package chatServer.data;

import chatProtocol.User;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
public class UsuarioDao {
    Database db;

    public UsuarioDao () {
        db = Database.instance();
    }

    public void create(User e) throws Exception {
        String sql = "insert into " +
                "Usuario " +
                "(id, nombre, clave) " +
                "values(?,?,?)";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, e.getId());
        stm.setString(2, e.getNombre());
        stm.setString(3, e.getClave());

        db.executeUpdate(stm);
    }

    public User read(String codigo) throws Exception {
        String sql = "select " +
                "* " +
                "from  Usuario s " +
                "where s.id=?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, codigo);
        ResultSet rs = db.executeQuery(stm);
        if (rs.next()) {
            return from(rs, "s");
        } else {
            throw new Exception("USUARIO NO EXISTE");
        }
    }

    public void update(User e) throws Exception {
        String sql = "update " +
                "Usuario " +
                "set nombre=?, clave=? " +
                "where id=?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, e.getNombre());
        stm.setString(2, e.getClave());
        stm.setString(3, e.getId());
        int count = db.executeUpdate(stm);
        if (count == 0) {
            throw new Exception("USUARIO NO EXISTE");
        }

    }

    public void delete(User e) throws Exception {
        String sql = "delete " +
                "from Usuario " +
                "where id=?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, e.getId());
        int count = db.executeUpdate(stm);
        if (count == 0) {
            throw new Exception("USUARIO NO EXISTE");
        }
    }

    public List<User> findByReferencia(String referencia) throws Exception {
        List<User> resultado = new ArrayList<User>();
        String sql = "select * " +
                "from " +
                "Usuario s " +
                "where s.nombre like ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, "%" + referencia + "%");
        ResultSet rs = db.executeQuery(stm);
        while (rs.next()) {
            resultado.add(from(rs, "s"));
        }
        return resultado;
    }

    public User from(ResultSet rs, String alias) throws Exception {
        User e = new User();
        e.setId(rs.getString(alias + ".id"));
        e.setNombre(rs.getString(alias + ".nombre"));
        e.setClave(rs.getString(alias + ".clave"));
        return e;
    }
}
