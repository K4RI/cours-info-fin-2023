package webstore;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;

import webstore.business.Article;

// https://koor.fr/Java/TutorialJEE/jee_jpa_introduction.wp

public class ConsoleJPA {

   public static void main(String[] args) throws Exception {

    // org.hibernate.jpa.HibernatePersistenceProvider h = new org.hibernate.jpa.HibernatePersistenceProvider();
    EntityManagerFactory entityManagerFactory = null;
    EntityManager entityManager = null;
    try {
        entityManagerFactory = Persistence.createEntityManagerFactory("WebStore");
        entityManager = entityManagerFactory.createEntityManager();
    
        System.out.println( "- Lecture de tous les articles -----------" );
        
        List<Article> articles = entityManager.createQuery( "from Article", Article.class )
                                .getResultList();
        for (Article article : articles) {
            System.out.println( article );
        }
        
        System.out.println( "- Insertion d'un nouvel article ----------" );
        
        EntityTransaction trans = entityManager.getTransaction();
        trans.begin();
        
        Article newArticle = new Article( "DBS", "Aston Martin", 200000 );
        entityManager.persist( newArticle );

        List<Article> results = entityManager.createQuery("from Article", Article.class).getResultList();
        for( Article article : results) {
            System.out.println( article );
        }

        System.out.println( "- Modification d'un article --------------" );
    
        newArticle.setPrice( 40000 );
        entityManager.persist( newArticle );
        
        results = entityManager.createQuery("from Article", Article.class).getResultList();
        for( Article article : results) {
            System.out.println( article );
        }

        System.out.println( "- Suppression d'un article ---------------" );
        
        entityManager.remove( newArticle );
        
        results = entityManager.createQuery("from Article", Article.class).getResultList();
        for( Article article : results) {
            System.out.println( article );
        }
                
        trans.commit();
    } finally {
        if ( entityManager != null ) entityManager.close();
        if ( entityManagerFactory != null ) entityManagerFactory.close();
    }
}
}
