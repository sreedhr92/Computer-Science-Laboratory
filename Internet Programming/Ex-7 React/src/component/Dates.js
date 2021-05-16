import React from 'react';
import logo from './beast.jpg';
const Dates = () => {
    return ( <div>
        <img src={logo} width={100} height={80} alt="Page logo" />
        <h2>International Gaming Conference Dates</h2>
        <hr className="solid" />
        <br /><br /><br />
        <font color="f58634">
        </font><font color="f58634"><font color="d9dab0">
          </font></font><table>
          <caption><strong>Important Dates of the Conference</strong></caption>
          <thead>
            <tr>
              <th>Date</th>
              <th>Event</th>
            </tr>
          </thead>
          <tbody>
            <tr>
              <td>29.01.2021</td>
              <td>Workshop</td>
            </tr>
            <tr>
              <td>30.01.2021</td>
              <td>Committe Speach</td>
            </tr>
            <tr>
              <td>31.01.2021</td>
              <td>Paper Presentation</td>
            </tr>
            <tr>
              <td>01.02.2021</td>
              <td>Live Gaming Session</td>
            </tr>
          </tbody>
        </table><font color="f58634"><font color="d9dab0">
            <br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />
            <footer className="mail" background="white">
              <font color="brown">
                <p style={{color: 'gray'}}>Author: Sreedhar V
                  <br /> <a href="mailto:sreedhar18161@cse.ssn.edu.in">Mail id</a></p>
                <i>©Gaming techs designs</i><br />
                <a href="index.html" target="_blank" data-toggle="tooltip" title="This directs you to index page"><i className="fas fa-arrow-left" /></a>
              </font></footer><font color="brown">
            </font></font></font>
    </div> );
}
 
export default Dates;