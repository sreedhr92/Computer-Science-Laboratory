import React from 'react';
import logo from './beast.jpg';

const Home = () => {
    return ( <div>
        <img src={logo} width={50} height={40} alt="Page logo" />
        <h1>
          <strong style={{color: 'orange'}}>Gaming Conference</strong></h1>
        <hr className="solid" />
        <div className="box">
          <article>
            <header>
              <font color={557174}>
                <h4>OVERVIEW</h4>
              </font>
              <font color="16697a">
                <p color="16117a"> Today, it is globally recognized that fulfilling the <em>rights of women</em> and girls is central to development. But if one were to trace the origins of this realization, many threads would lead back to Cairo in 1994.</p>
                <p> A quarter of a century later, the world has seen remarkable progress. There has been a 25 per cent increase in global contraceptive prevalence rate around the world.<br /> Adolescent births have declined steeply, and the global maternal mortality ratio has fallen. But progress has been slow and uneven. Hundreds of millions of women around the world are still not using modern contraceptives to prevent unwanted pregnancies, and global targets on reducing maternal deaths have not been met.</p>
              </font>
            </header>
          </article>
        </div>
        <div className="coloumn">
          <img className="fade-out" src="mario.jpg" alt="Mario" />
        </div>
        <footer>
          <p style={{color: 'gray'}}>Author: Sreedhar V
            <br /> <a href="mailto:sreedhar18161@cse.ssn.edu.in">Mail id</a></p>
          <i>©Gaming techs designs</i><br />
          <a href="index.html" target="_blank" data-toggle="tooltip" title="This directs you to index page"><i className="fas fa-arrow-left" /></a>
        </footer>

    </div> );
}
 
export default Home;