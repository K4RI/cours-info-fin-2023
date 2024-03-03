package td;
import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

/**
 *
* @author charoy
*/
@Entity
public class Action implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Integer id;
    private int type;
    private int strength;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (id != null ? id.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Action)) {
            return false;
        }
        Action other = (Action) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "Action[ id=" + id + " ]";
    }

    /**
     * @return the type
    */
    public int getType() {
        return type;
    }

    /**
     * @param type the type to set
    */
    public void setType(int type) {
        this.type = type;
    }

    /**
     * @return the strength
    */
    public int getStrength() {
        return strength;
    }

    /**
     * @param strength the strength to set
    */
    public void setStrength(int strength) {
        this.strength = strength;
    }
     
 }
 