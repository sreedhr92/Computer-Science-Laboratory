import React from 'react';
import logo from './beast.jpg';
import logo_1 from './pewds.jpg';
import logo_2 from './lg1.jpg';

const Committe = () => {
    return (<div>
        <img src={logo_2} width={100} height={80} alt="Page logo" />
        <font color="16a596">
          <strong>
            <h2>International Gaming Conference Committee</h2>
            <hr className="solid" />
          </strong></font>
          <div className="box_1">
          <ol>
            <br /><br />
            <font color="#db6400">
              <li>Local Chair
                <font color="#03506f">
                  <ul>
                    <br />
                    <li>Laser Beam<img src={logo_1} alt="Page logo" width={100} height={100} /></li>
                    <br />
                    <li>Dream</li>
                  </ul>
                  <br /><br />
                  <font color="#db6400">
                  </font></font></li><li><font color="#03506f"><font color="#db6400">Finance Chair
                    <font color="#03506f">
                      <ul>
                        <br />
                        <li>MrBeast<img src={logo} alt="Page logo" width={100} height={100} /> </li>
                        <br />
                        <li>Judo Sloth</li>
                      </ul>
                      <br /><br />
                    </font></font></font></li></font></ol><font color="#db6400"><font color="#03506f"><font color="#db6400"><font color="#03506f">
                </font></font></font></font></div><font color="#db6400"><font color="#03506f"><font color="#db6400"><font color="#03506f">
                <footer className="mail">
                  <p style={{color: 'gray'}}>Author: Sreedhar V
                    <br /> <a href="mailto:sreedhar18161@cse.ssn.edu.in">Mail id</a></p>
                  <i>©Gaming techs designs</i><br />
                  <a href="index.html" target="_blank" data-toggle="tooltip" title="This directs you to index page"><i className="fas fa-arrow-left" /></a>
                </footer>
              </font></font></font></font>

    </div>  );
}
 
export default Committe;